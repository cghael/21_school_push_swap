//
// Created by Anton on 18.04.2020.
//

#include "push_swap.h"

static void		ft_return_from_dst(t_order **cmd_stack, t_elem **src, \
								t_elem **dst, int pivot)
{
	t_elem	*tmp;

	tmp = *dst;
	while (pivot)
	{
		ft_pa_pb(cmd_stack, dst, src);
		ft_print_stack_step(*src, *dst); //TODO del
		(*src)->iter = (*src)->next->iter;
		pivot--;
	}
}

static void		ft_sort_two_three_elem(t_order **cmd, t_elem **stack, char name)
{
	if ((*stack)->qnty == 2 && (*stack)->index > (*stack)->next->index)
		ft_ra_rb(cmd, stack, name);
	if (STACK_NOT_SORTED == ft_check_stack_sorted(*stack))
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
	if (STACK_NOT_SORTED == ft_check_stack_sorted(*stack))
		ft_sort_two_three_elem(cmd, stack, name);
}

static void		ft_start_sorting(t_order **cmd_stack, t_elem **stack_src, \
								t_elem **stack_dst)
{
	int	pivot;

	pivot = (*stack_src)->qnty / 2;
	ft_print_stack_step(*stack_src, *stack_dst); //TODO del

//	if ((*stack_src && (*stack_src)->qnty <= 3) \
//		|| (*stack_dst && (*stack_dst)->qnty <= 3))
//		ft_sort_last_step(cmd_stack, stack_src, stack_dst);

	ft_push_to_dst_before_pivot(cmd_stack, stack_src, stack_dst, pivot);

//	ft_start_sorting(cmd_stack, stack_src, stack_dst);
//	ft_start_sorting(cmd_stack, stack_dst, stack_src);

	ft_return_from_dst(cmd_stack, stack_src, stack_dst, pivot);
	ft_print_stack_step(*stack_src, *stack_dst); //TODO del
}

void			ft_sort_stacks(t_st *stacks)
{
	ft_print_stack_step(stacks->a, stacks->b); //TODO del
	if (STACK_NOT_SORTED == ft_check_stack_sorted(stacks->a))
	{
		ft_putstr("NOT_SORTED\n\n"); //TODO del
		if (stacks->a->qnty <= 3)
			ft_sort_two_three_elem(&(stacks->cmd), &(stacks->a), stacks->a->name);
//		else
//			ft_start_sorting(&cmd_stack, &stack_a, &stack_b);
	}
	ft_print_stack_step(stacks->a, stacks->b); //TODO del
	ft_putstr("SORTED\n\n"); //TODO del
}