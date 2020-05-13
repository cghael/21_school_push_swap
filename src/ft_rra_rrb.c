//
// Created by Anton on 25.04.2020.
//

#include "push_swap.h"

void		ft_rra_rrb(t_order **cmd_stack, t_elem **stack, char ch)
{
	t_elem *tmp;

	if (*stack)
	{
		tmp = (*stack)->back;
		tmp->qnty = (*stack)->qnty;

		(*stack)->qnty = 0;
		*stack = tmp;
		if (ch == 'a')
			ft_new_order_add(cmd_stack, "rra");
		else if (ch == 'b')
			ft_new_order_add(cmd_stack, "rrb");
	}
}
