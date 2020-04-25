//
// Created by Anton on 25.04.2020.
//

#include "push_swap.h"

void		ft_rra_rrb(t_order **cmd_stack, t_elem **stack, char ch)
{
	t_elem *tmp;

	tmp = (*stack)->back;
	tmp->qnty = (*stack)->qnty;

	(*stack)->qnty = 0;
	*stack = tmp;
	if (ch == 'a')
		ft_new_order_add(cmd_stack, "rra");
	else
		ft_new_order_add(cmd_stack, "rrb");
}