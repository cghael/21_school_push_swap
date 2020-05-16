//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

void		ft_move_src_elem_to_dst(t_order **cmd_stack, t_elem **src, \
										t_elem **dst, t_elem *tmp)
{
	//move tmp elem at the top of src
	while(*src != tmp) //todo can make faster, first rotate side then rotate
	{
		if (ROTATE == ft_find_rotate_side(*src, tmp->index))
			ft_ra_rb(cmd_stack, src, (*src)->name);
		else
			ft_rra_rrb(cmd_stack, src, (*src)->name);
		ft_print_stack_step(
				*src); //TODO del
	}
	ft_pa_pb(cmd_stack, src, dst);
	ft_print_stack_step(
			*src); //TODO del
}

void		ft_push_to_dst_before_pivot(t_order **cmd_stack, t_elem **src, \
														t_elem **dst, int pivot)
{
	int		n;
	int		iter;
	t_elem	*tmp;

	n = pivot;
	tmp = *src;
	iter = (*src)->iter;
	while (n)
	{
		if (tmp->index < pivot && tmp->iter == iter)
		{
			tmp->iter++;
			ft_move_src_elem_to_dst(cmd_stack, src, dst, tmp);
			tmp = *src;
			n--;
		}
		else
		{
			if (ROTATE == ft_nearest_smaller_pivot(*src, pivot))
				tmp = tmp->next;
			else
				tmp = tmp->back;
		}
	}
}