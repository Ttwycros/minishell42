/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:12:12 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 15:12:18 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	ft_count_redirects(t_list **cmd)
{
	int		count;
	t_list	*tmp;

	tmp = *cmd;
	count = 0;
	while (tmp)
	{
		if (!ft_strncmp((const char *)tmp->content, ">", 2))
			count++;
		if (!ft_strncmp((const char *)tmp->content, "<", 2))
			count++;
		if (!ft_strncmp((const char *)tmp->content, ">>", 3))
			count++;
		if (!ft_strncmp((const char *)tmp->content, "<<", 3))
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	ft_is_redirect(char	*str)
{
	if (!ft_strncmp(str, ">", 2))
		return (4);
	if (!ft_strncmp(str, ">>", 3))
		return (1);
	if (!ft_strncmp(str, "<", 2))
		return (2);
	if (!ft_strncmp(str, "<<", 2))
		return (3);
	return (-1);
}
