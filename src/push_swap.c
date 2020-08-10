/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:51:12 by cghael            #+#    #+#             */
/*   Updated: 2020/06/25 13:15:03 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char *argv[])
{
	t_st	*stacks;

	stacks = ft_check_n_write_args(argc, argv, 1);
	ft_sort_stacks(&stacks);
	ft_print_operations(stacks->cmd);
	ft_free_push_swap_mem(stacks);
	return (0);
}
