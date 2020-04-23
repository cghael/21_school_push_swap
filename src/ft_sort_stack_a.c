//
// Created by Anton on 18.04.2020.
//

#include "push_swap.h"

static void		ft_start_sorting(t_order **cmd_stack, t_elem *stack_a)
{
	t_elem	*stack_b;

	stack_b = NULL;
	ft_print_stack_step(stack_a, stack_b); //TODO del
	ft_push_to_b_after_pivot(cmd_stack, &stack_a, &stack_b);
}

t_order			*ft_sort_stack_a(t_elem *stack_a)
{
	t_order	*cmd_stack;

	cmd_stack = NULL;
	if (STACK_NOT_SORTED == ft_check_stack_sorted(stack_a))
	{
		ft_putstr("NOT_SORTED\n\n"); //TODO del
		ft_start_sorting(&cmd_stack, stack_a);
	}
	ft_putstr("SORTED\n\n"); //TODO del
	return (cmd_stack);
}