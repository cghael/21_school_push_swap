//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

void		ft_ra_rb(t_order **cmd_stack, t_elem **stack, char ch)
{
	t_elem *tmp;

	if (*stack)
	{
		tmp = (*stack)->next;
		tmp->qnty = (*stack)->qnty;

		(*stack)->qnty = 0;
		*stack = tmp;
		if (ch == 'a')
			ft_new_order_add(cmd_stack, "_ra");
		else
			ft_new_order_add(cmd_stack, "_rb");
	}
}