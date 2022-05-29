/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_parser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:07:31 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 15:07:41 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/envp_parser.h"

t_llist	*ft_init_envp_list(char **envp)
{
	t_llist	*env;
	int		i;
	char	**key_val;
	int		j;

	env = NULL;
	i = 0;
	while (envp[i])
	{
		key_val = ft_split(envp[i], '=');
		j = 0;
		if (!env)
			env = ft_lstnew_envp(key_val[0], key_val[1]);
		else
			ft_lstadd_back_envp(&env, ft_lstnew_envp(key_val[0], key_val[1]));
		while (key_val[j])
			j++;
		free(key_val);
		i++;
	}
	return (env);
}

t_llist	*ft_lstnew_envp(char *key, char *value)
{
	t_llist	*item;

	item = malloc(sizeof(t_llist));
	if (!item)
		return (NULL);
	item->key = key;
	item->value = value;
	item->next = NULL;
	return (item);
}

void	ft_lstadd_back_envp(t_llist **lst, t_llist *new)
{
	t_llist	*ptr;

	if (lst)
	{
		ptr = *lst;
		if (*lst)
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = new;
		}
		else
			*lst = new;
	}
}
