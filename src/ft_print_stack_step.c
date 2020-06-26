/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack_step.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:24:45 by cghael            #+#    #+#             */
/*   Updated: 2020/06/25 13:24:52 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_line(int counter, t_elem **tmp, char ch)
{
	if (counter > 0)
	{
		if (ch == 'a')
			ft_printf("%7d", (*tmp)->index);
		else
			ft_printf("|%7d\n", (*tmp)->index);
		*tmp = (*tmp)->next;
	}
	else
	{
		if (ch == 'a')
			ft_printf("       ");
		else
			ft_printf("|       \n");
	}
}

void		ft_print_stack_step(t_st *stacks)
{
	int		counter_a;
	int		counter_b;

	counter_a = (stacks->a) ? stacks->qnty_a : 0;
	counter_b = (stacks->b) ? stacks->qnty_b : 0;
	ft_printf("STACK A|STACK B\n-------|-------\n");
	while (counter_a > 0 || counter_b > 0)
	{
		ft_print_line(counter_a, &stacks->a, 'a');
		ft_print_line(counter_b, &stacks->b, 'b');
		counter_a--;
		counter_b--;
	}
	ft_printf("---------------\n\n");
}
