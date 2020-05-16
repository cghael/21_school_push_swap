//
// Created by Anton on 18.04.2020.
//

#include "push_swap.h"

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

static void		ft_return_from_dst(t_order **cmd, t_elem **src, \
													t_elem **dst, int moved_now)
{
	while (moved_now)
	{
		ft_pa_pb(cmd, dst, src);
		ft_print_stack_step(*src, *dst); //TODO del
		moved_now--;
	}
}

static void		ft_start_sorting(t_order **cmd, t_elem **src, t_elem **dst, int move)
{
	int	moved_now;

	moved_now = move / 2;

	if (*src && (*src)->qnty <= 3)
		ft_sort_last_step(cmd_stack, stack_src, stack_dst);

	ft_push_to_dst_before_pivot(cmd, src, dst, move);

//	ft_start_sorting(cmd, src, dst, moved_now);
//	ft_start_sorting(cmd, dst, src, move - moved_now);

	ft_return_from_dst(cmd, src, dst, moved_now);
}

void			ft_sort_stacks(t_st *stacks)
{
	int		move;

	move = stacks->a->qnty;
	ft_print_stack_step(stacks->a, stacks->b); //TODO del
	if (STACK_NOT_SORTED == ft_check_stack_sorted(stacks->a))
	{
		ft_putstr("NOT_SORTED\n\n"); //TODO del
		if (move <= 3)
			ft_sort_two_three_elem(&(stacks->cmd), &(stacks->a), stacks->a->name);
		else
			ft_start_sorting(&(stacks->cmd), &(stacks->a), &(stacks->b), move);
	}
	ft_print_stack_step(stacks->a, stacks->b); //TODO del
	ft_putstr("SORTED!!!\n\n"); //TODO del
}