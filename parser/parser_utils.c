/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:12:30 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 17:46:36 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

char	*ft_strjoin_mod1(char *s1, char ch)
{
	int		len1;
	char	*str;
	int		i;

	i = 0;
	len1 = ft_strlen(s1);
	str = malloc(sizeof(*str) * (len1 + 1) + 1);
	if (str == 0)
		return (0);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = ch;
	i++;
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_pop_front_cpy(t_list **head)
{
	t_list	*prev;
	char	*val;

	prev = NULL;
	if (head == NULL)
		return (NULL);
	prev = (*head);
	val = ft_strdup((char *)prev->content);
	(*head) = (*head)->next;
	return (val);
}

void	free_help(t_list **t, char **str)
{
	free((*t)->content);
	(*t)->content = (void *)ft_strdup(*str);
	free(*str);
	*t = (*t)->next;
}

void	clear_lexemex(t_list **lex)
{
	t_list	*lexems;
	t_list	*temp;

	lexems = *lex;
	while (lexems)
	{
		free(lexems->content);
		temp = lexems->next;
		free(lexems);
		lexems = temp;
	}
}
