//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

static t_elem	*ft_move_src_elem_to_dst(t_order **cmd, t_elem **src, \
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
	return (*src);
}

static int		ft_find_elem_qnty(int pivot, t_elem **src, int move)
{
	t_elem	*tmp;
	int		counter;

	tmp = *src;
	counter = 0;
	while (move)
	{
		if (((*src)->name == 'a' && tmp->index < pivot) \
			|| ((*src)->name == 'b' && tmp->index >= pivot))
			counter++;
		tmp = tmp->next;
		move--;
	}
	return (counter);
}

int				ft_push_to_dst_before_pivot(t_order **cmd, t_elem **src, \
														t_elem **dst, int move)
{
	int		pivot;
	t_elem	*tmp;
	t_elem	*last;
	int		counter;

	last = NULL;
	if ((*src)->qnty != move)
		last = (*src)->back;
	counter = 0;
	pivot = ft_find_pivot(*src, move);
	ft_printf("Pivot = %d\n\n", pivot); //todo del-------------------
	tmp = *src;
	move = ft_find_elem_qnty(pivot, src, move);
	while (counter != move)
	{
		if (((*src)->name == 'a' && tmp->index < pivot) \
			|| ((*src)->name == 'b' && tmp->index >= pivot))
		{
			tmp = ft_move_src_elem_to_dst(cmd, src, dst, tmp);
			counter++;
		}
		else
		{
			if (ROTATE == ft_side_to_rotate(pivot, src))
				tmp = tmp->next;
			else
				tmp = tmp->back;
		}
	}
	ft_print_stack_step(*src, *dst); //TODO del-------------------------------
	if (last) //todo do not like this, but it work
	{
		while ((*src)->back != last)
			ft_rra_rrb(cmd, src, (*src)->name);
	}
	ft_print_stack_step(*src, *dst); //TODO del--------------------------------
	return (counter);

}