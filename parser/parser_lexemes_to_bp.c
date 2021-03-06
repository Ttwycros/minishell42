/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexemes_to_bp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:11:28 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 17:43:02 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	ft_fill_argv_in_bp(char **argv, t_list **cmd, int num)
{
	t_list	*tmp;
	int		i;
	int		redir;

	i = 0;
	tmp = *cmd;
	while (i < num && tmp)
	{
		redir = ft_is_redirect((char *)tmp->content);
		if (redir == -1)
		{
			argv[i] = ft_strdup((char *)tmp->content);
			i++;
		}
		tmp = tmp->next;
	}
	argv[i] = NULL;
}

void	ft_fill_redirect_info(t_block_process *block, t_list **cmd)
{
	t_list		*tmp;
	int			i;
	int			redir;
	t_file_info	*files;

	i = 0;
	tmp = *cmd;
	files = malloc(sizeof(t_file_info) * block->files_count);
	if (!files)
		return ;
	while (i < block->files_count && tmp)
	{
		redir = ft_is_redirect((char *)tmp->content);
		if (redir != -1)
		{
			if (tmp->next)
				files[i].file_name = ft_strdup((char *)tmp->next->content);
			files[i].redirect_type = redir;
			i++;
		}
		tmp = tmp->next;
	}
	block->files = files;
}

t_block_process	*ft_create_bp(t_list **cmd)
{
	t_block_process	*block;
	t_list			*tmp;

	tmp = *cmd;
	block = malloc(sizeof(t_block_process));
	if (!block)
		return (NULL);
	block->files_count = ft_count_redirects(cmd);
	block->argc = ft_lstsize(tmp) - block->files_count;
	block->argv = malloc(sizeof(char *) * (block->argc + 1));
	if (!block->argv)
		return (NULL);
	ft_fill_argv_in_bp(block->argv, &tmp, block->argc);
	ft_fill_redirect_info(block, cmd);
	ft_delete_list_mod(cmd);
	return (block);
}

int	ft_create_bp_list(t_list **bp, t_list **cmd, t_llist *envp)
{
	if (!(*bp) && !(*cmd))
		return (ft_print_parse_error(PARSER_ERR_PIPE));
	if (ft_check_redirect_error(cmd))
		return (1);
	ft_delete_quotes(cmd, envp);
	if (!(*bp))
	{
		*bp = ft_lstnew((void *)ft_create_bp(cmd));
		if (!(*bp))
			return (1);
	}
	else
		ft_lstadd_back(bp, ft_lstnew((void *)ft_create_bp(cmd)));
	return (0);
}

int	ft_lexemes_to_bp(t_list **bp, t_list **lexemes, t_llist *envp)
{
	t_list	*lex;
	t_list	*cmd;

	lex = *lexemes;
	cmd = NULL;
	while (lex)
	{
		if (ft_check_pipe_error(lex))
			return (1);
		if (!ft_strncmp((const char *)lex->content, "|", 2))
		{
			lex = lex -> next;
			if (ft_create_bp_list(bp, &cmd, envp))
				return (1);
		}
		else
		{
			ft_lstadd_back(&cmd, ft_lstnew((void *)ft_pop_front_cpy(&lex)));
			if (!lex)
				if (ft_create_bp_list(bp, &cmd, envp))
					return (1);
		}
	}
	return (0);
}
