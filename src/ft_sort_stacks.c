//
// Created by Anton on 18.04.2020.
//

#include "push_swap.h"

static int		ft_check_all_stacks_sort(t_order **cmd, t_elem **src, t_elem **dst)
{
	if (STACKS_SORTED == ft_check_stack_sorted(*src, (*src)->qnty) \
		&& STACK_SORTED == ft_check_stack_sorted(*dst, (*dst)->qnty))
	{
		if ((*src)->name == 'a')
		{
			while (*dst)
				ft_pa_pb(cmd, dst, src);
		}
		else
		{
			while (*src)
				ft_pa_pb(cmd, src, dst);
		}
		return (STACKS_SORTED);
	}
	return (STACK_NOT_SORTED);
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

static int		ft_start_sorting(t_order **cmd, t_elem **src, t_elem **dst, int move)
{
	int	moved_now;

	if (STACKS_SORTED == ft_check_all_stacks_sort(cmd, src, dst))
		return (STACKS_SORTED);
	if (STACK_SORTED == ft_check_stack_sorted(*src, move))
		return (0);
	if (move <= 3)
	{
		ft_sort_last_step(cmd, src, 0);
		ft_print_stack_step(*src, *dst); //TODO del
		if (STACKS_SORTED == ft_check_all_stacks_sort(cmd, src, dst))
			return (STACKS_SORTED);
	}
	else
	{
		moved_now = ft_push_to_dst_before_pivot(cmd, src, dst, move);
		if (STACKS_SORTED == ft_start_sorting(cmd, src, dst, move - moved_now))
			return (STACKS_SORTED);
		if (STACKS_SORTED == ft_start_sorting(cmd, dst, src, moved_now))
			return (STACKS_SORTED);
		ft_return_from_dst(cmd, src, dst, moved_now);
	}
	return (0);
}

void			ft_sort_stacks(t_st *stacks)
{
	int		move;

	move = stacks->a->qnty;
	ft_print_stack_step(stacks->a, stacks->b); //TODO del
	if (STACK_NOT_SORTED == ft_check_stack_sorted(stacks->a, move))
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