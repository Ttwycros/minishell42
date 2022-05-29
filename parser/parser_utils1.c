/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:12:55 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 15:13:02 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

char	*ft_pop_front(t_list **head)
{
	t_list	*prev;
	char	*val;

	prev = NULL;
	if (head == NULL)
		return (NULL);
	prev = (*head);
	val = (char *)prev->content;
	(*head) = (*head)->next;
	free(prev);
	return (val);
}

void	ft_delete_list(t_list **head)
{
	t_list	*prev;

	prev = NULL;
	while ((*head)->next)
	{
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	*head = NULL;
	free(*head);
}

void	ft_delete_list_mod(t_list **head)
{
	t_list	*prev;

	prev = NULL;
	while ((*head))
	{
		prev = (*head);
		(*head) = (*head)->next;
		free(prev->content);
		free(prev);
	}
}

int	ft_isspace(char s)
{
	if (s == ' ' || s == '\t' || s == '\n' || \
s == '\v' || s == '\f' || s == '\r')
		return (1);
	return (0);
}

int	ft_check_quotes(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 34)
		{
			i++;
			while (line[i] && line[i] != 34)
				i++;
			if (!line[i])
				return (ft_print_parse_error(ERR_DOUBLE_QUOTES));
		}
		if (line[i] == 39)
		{
			i++;
			while (line[i] && line[i] != 39)
				i++;
			if (!line[i])
				return (ft_print_parse_error(ERR_SINGLE_QUOTES));
		}
		i++;
	}
	return (0);
}
