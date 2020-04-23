//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

void		ft_move_a_and_adjust_b(t_order **cmd_stack, t_elem **stack_a, \
										t_elem **stack_b, t_elem *tmp)
{
	while(*stack_a != tmp)
	{
		//TODO choose the side to rotate stack
		ft_ra_rb(cmd_stack, stack_a, 'a');
		ft_print_stack_step(*stack_a, *stack_b); //TODO del
	}
	if (*stack_b)
	{
		//TODO find the elem in stack_b to adjust
		//ft_adjust_smallest_bigger(cmd_stack, stack_b, tmp->index);
	}
	ft_pa_pb(cmd_stack, stack_a, stack_b, 'b');
	ft_print_stack_step(*stack_a, *stack_b); //TODO del
}

void		ft_push_to_b_after_pivot(t_order **cmd_stack, t_elem **stack_a, \
										t_elem **stack_b)
{
	int		pivot;

	int		n;
	t_elem	*tmp;

	pivot = ((*stack_a)->qnty / 2 + (*stack_a)->qnty % 2) - 1;
	n = (*stack_a)->qnty;
	tmp = *stack_a;
	while (n)
	{
		if (tmp->index > pivot)
		{
			ft_move_a_and_adjust_b(cmd_stack, stack_a, stack_b, tmp);
			tmp = *stack_a;
		}
		else
			tmp = tmp->next;
		n--;
	}
}