/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:55:40 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 14:55:47 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	ft_echo_help(char **args, int *j)
{
	int	i;

	i = *j;
	while (args[i])
	{
		ft_putstr_fd(args[i++], g_global.builtin_fd);
		if (args[i])
			ft_putstr_fd(" ", g_global.builtin_fd);
	}
	*j = i;
	return (0);
}

void	ft_echo(char **args)
{
	int	i;
	int	flag;

	g_global.last_return = 1;
	i = 1;
	flag = 0;
	if (args[1] && !ft_strcmp(args[1], "-n"))
	{
		flag = 1;
		i++;
	}
	if (ft_echo_help(args, &i))
		return ;
	if (flag != 1)
		ft_putstr_fd("\n", g_global.builtin_fd);
	g_global.last_return = 0;
}
