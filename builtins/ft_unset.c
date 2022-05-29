/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:58:15 by ameteori          #+#    #+#             */
/*   Updated: 2022/05/29 14:58:33 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/builtins.h"
#include "../includes/envp_parser.h"

void	ft_unset(t_block_process *block)
{
	ft_remove_elem_envp(&g_global.envp_list, block->argv[1]);
	g_global.last_return = 0;
}
