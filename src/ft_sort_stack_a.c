//
// Created by Anton on 18.04.2020.
//

#include "push_swap.h"

//static void		ft_sort_three_elem(t_order **cmd_stack, t_elem *stack_a)
//{
//	if (stack_a->index - stack_a->next->index == 1)
//		ft_sa(cmd_stack, stack_a);
//	else if (stack_a->index - stack_a->next->index == -1)
//}

static void		ft_start_sorting(t_order **cmd_stack, t_elem *stack_a)
{
	t_elem	*stack_b;
	int		pivot;
	int		n;
	t_elem	*tmp;

	stack_b = NULL;
	ft_print_stack_step(stack_a, stack_b); //TODO del
	pivot = (stack_a->qnty / 2 + stack_a->qnty % 2) - 1;
//	if (stack_a->qnty <= 3)
//		ft_sort_three_elem(cmd_stack, stack_a);
	n = stack_a->qnty;
	tmp = stack_a;
	while (n)
	{
		if (tmp->index > pivot)
		{
			ft_pa_pb(cmd_stack, &stack_a, &stack_b);
			ft_print_stack_step(stack_a, stack_b); //TODO del
			tmp = stack_a;
		}
		else
			tmp = tmp->next;
		n--;
	}
}

t_order			*ft_sort_stack_a(t_elem *stack_a)
{
	t_order	*cmd_stack;

	cmd_stack = NULL;
	if (STACK_NOT_SORTED == ft_check_stack_sorted(stack_a))
	{
//		ft_new_order_add(&cmd_stack, "_sa"); //TODO del
//		ft_new_order_add(&cmd_stack, "ssa"); //TODO del
		ft_putstr("NOT_SORTED\n"); //TODO del
		ft_start_sorting(&cmd_stack, stack_a);
	}
	ft_putstr("SORTED\n\n"); //TODO del
	return (cmd_stack);
}