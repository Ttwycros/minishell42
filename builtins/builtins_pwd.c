/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:57:34 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 14:57:40 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"
#include <sys/param.h>

void	ft_pwd(char **args, t_llist __unused *envp)
{
	char	buf[MAXPATHLEN];

	if (args[1])
	{
		ft_putstr_fd("pwd: too many arguments\n", g_global.builtin_fd);
		g_global.last_return = 1;
		return ;
	}
	if (getcwd(buf, MAXPATHLEN) == NULL)
	{
		g_global.last_return = 1;
		return ;
	}
	g_global.last_return = 0;
	ft_putendl_fd(buf, g_global.builtin_fd);
}
