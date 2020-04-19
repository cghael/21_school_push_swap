//
// Created by Anton on 18.04.2020.
//

#include "push_swap.h"

t_order			*ft_sort_stack_a(t_elem *stack_a)
{
	t_order	*cmd_stack;

	cmd_stack = NULL;
	if (STACK_NOT_SORTED == ft_check_stack_sorted(stack_a))
	{
		ft_new_order_add(&cmd_stack, "_sa"); //TODO del
		ft_new_order_add(&cmd_stack, "ssa"); //TODO del
		ft_putstr("NOT_SORTED\n"); //TODO del
	}
	ft_putstr("SORTED\n\n"); //TODO del
	return (cmd_stack);
}