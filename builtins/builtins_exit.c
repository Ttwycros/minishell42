/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:57:13 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 14:57:20 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	ft_get_return(long long n)
{
	return ((n % 256 + 256) % 256);
}

void	ft_exit(char **args, t_llist __unused *envp)
{
	int	count;

	count = ft_get_args_count(args);
	if (count == 1)
		exit(1);
	if (count == 2 && !ft_check_digit(args[1]))
		exit(ft_get_return(ft_get_num(args[1])));
	if (ft_check_digit(args[1]))
	{
		ft_putendl_fd("exit", 1);
		ft_putstr_fd("minishell: exit: ", 1);
		ft_putstr_fd(args[1], 1);
		ft_putendl_fd(": numeric argument required", 1);
		exit(255);
	}
	else if (count > 2)
	{
		ft_putendl_fd("exit", 1);
		ft_putendl_fd("minishell: exit: too many arguments", 1);
		g_global.last_return = 1;
	}
}
