//
// Created by Anton on 17.05.2020.
//

#include "push_swap.h"

void		ft_sort_two_three_elem(t_order **cmd, t_elem **stack, char name)
{
	if ((*stack)->qnty == 2 && (*stack)->index > (*stack)->next->index)
		ft_ra_rb(cmd, stack, name);
	if (STACK_NOT_SORTED == ft_check_stack_sorted(*stack, (*stack)->qnty))
	{
		if ((*stack)->index > (*stack)->back->index \
			&& (*stack)->index < (*stack)->next->index)
			ft_rra_rrb(cmd, stack, name);
		else if ((*stack)->index > (*stack)->back->index \
			&& (*stack)->index > (*stack)->next->index)
			ft_ra_rb(cmd, stack, name);
		else
			ft_sa_sb(cmd, stack, name);
	}
	if (STACK_NOT_SORTED == ft_check_stack_sorted(*stack, (*stack)->qnty))
		ft_sort_two_three_elem(cmd, stack, name);
}