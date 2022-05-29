/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:04:38 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 15:04:45 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler(int code)
{
	if (code == SIGINT)
		ft_putstr_fd("\b\b\ni'm dead bro > ", 2);
	else if (code == SIGQUIT)
		ft_putstr_fd("\b\b", 1);
}
