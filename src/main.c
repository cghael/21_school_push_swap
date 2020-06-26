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

void		ft_count_operations(t_order *cmd_stack) //todo del
{
	t_order *tmp;
	int counter;

	tmp = cmd_stack;
	counter = 0;
	while (tmp)
	{
		counter++;
		tmp = tmp->next;
	}
	ft_printf("TOTAL OPERATIONS: %d\n", counter);
}

int			main(int argc, char *argv[])
{
	t_st	*stacks;

	stacks = ft_check_n_write_args(argc, argv);
	ft_sort_stacks(&stacks);
//	ft_print_operations(stacks->cmd);
	ft_count_operations(stacks->cmd); //TODO del
	ft_free_push_swap_mem(stacks);

	write(1, "----------\n", 11); //todo del
	write(1, "DONE!\n", 6); //todo del
	return (0);
}
