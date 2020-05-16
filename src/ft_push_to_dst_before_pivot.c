//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

void		ft_move_src_elem_to_dst(t_order **cmd, t_elem **src, \
													t_elem **dst, t_elem *tmp)
{
	while(*src != tmp)
	{
		if (ROTATE == ft_find_rotate_side(*src, tmp->index))
			ft_ra_rb(cmd, src, (*src)->name);
		else
			ft_rra_rrb(cmd, src, (*src)->name);
		ft_print_stack_step(*src, *dst); //TODO del
	}
	ft_pa_pb(cmd, src, dst);
	ft_print_stack_step(*src, *dst); //TODO del
}

static int		ft_find_pivot(t_elem *src, int move)
{
	int pivot;
	int counter;

	counter = move;
	pivot = 0;
	while (counter)
	{
		pivot += src->index;
		src = src->next;
		counter--;
	}
	pivot = pivot / move;
	if (move % 2 == 0)
		pivot++;
	return (pivot);
}

int			ft_push_to_dst_before_pivot(t_order **cmd, t_elem **src, \
														t_elem **dst, int move)
{
	int		pivot;
	t_elem	*tmp;
	int		counter;

	counter = 0;
	pivot = ft_find_pivot(*src, move);
	tmp = *src;
	while (move)
	{
		if (((*src)->name == 'a' && tmp->index < pivot) \
			|| ((*src)->name == 'b' && tmp->index >= pivot))
		{
			ft_move_src_elem_to_dst(cmd, src, dst, tmp);
			tmp = *src;
			counter++;
		}
		else
			tmp = tmp->next;
		move--;
	}
	return (counter);
}