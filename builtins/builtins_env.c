/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:56:17 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 14:56:18 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

void	ft_env(char **args)
{
	t_llist	*envp;

	envp = g_global.envp_list;
	if (args[1])
	{
		printf("env usage: env\n");
		g_global.last_return = 127;
		return ;
	}
	while (envp)
	{
		ft_putstr_fd(envp->key, g_global.builtin_fd);
		ft_putstr_fd("=", g_global.builtin_fd);
		ft_putendl_fd(envp->value, g_global.builtin_fd);
		envp = envp->next;
	}
	g_global.last_return = 0;
}
