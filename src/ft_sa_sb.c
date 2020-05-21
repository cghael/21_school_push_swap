//
// Created by Anton on 26.04.2020.
//

#include "push_swap.h"

void		ft_sa_sb(t_order **cmd_stack, t_elem **stack, char ch)
{
	t_elem *tmp;

	tmp = (*stack)->next;
//	tmp->qnty = (*stack)->qnty;
//	(*stack)->qnty = 0;
	(*stack)->next = tmp->next;
	tmp->next->back = *stack;
	tmp->next = *stack;
	tmp->back = (*stack)->back;
	(*stack)->back->next = tmp;
	(*stack)->back = tmp;
	*stack = tmp;
	if (ch == 'a')
		ft_new_order_add(cmd_stack, "_sa");
	else
		ft_new_order_add(cmd_stack, "_sb");
}