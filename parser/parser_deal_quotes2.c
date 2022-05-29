/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_deal_quotes2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:10:23 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 15:10:36 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../includes/builtins.h"

char	*ft_deal_single_quote(char *str, int *j, char *to_copy)
{
	int		i;

	i = *j;
	i++;
	while (to_copy[i] != 39)
	{
		str = ft_strjoin_mod1(str, to_copy[i]);
		i++;
	}
	i++;
	*j = i;
	return (str);
}

char	*ft_strjoin_clean(char *s1, char *s2)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (0);
	while (s1[i])
	{
		out[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		out[j++] = s2[i++];
	}
	free(s1);
	free(s2);
	out[j] = '\0';
	return (out);
}
