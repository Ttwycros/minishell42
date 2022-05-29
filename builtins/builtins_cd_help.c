/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:54:36 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 14:54:37 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

void	ft_change_old_dir_envp(char *path, t_llist **envp)
{
	t_llist	*env;

	env = *envp;
	while (env)
	{
		if (!(ft_strcmp("OLDPWD", env->key)))
		{
			free(env->value);
			env->value = ft_strdup(path);
			return ;
		}
		env = env->next;
	}
}

void	ft_change_new_dir_envp(char *path, t_llist **envp)
{
	t_llist	*env;

	env = *envp;
	while (env)
	{
		if (!(ft_strcmp("PWD", env->key)))
		{
			free(env->value);
			env->value = ft_strdup(path);
			return ;
		}
		env = env->next;
	}
}
