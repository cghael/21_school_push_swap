/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:54:41 by cghael            #+#    #+#             */
/*   Updated: 2020/07/14 14:54:47 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_move_first_elem_on_top_b(t_st **stacks)
{
	int		rotate;
	t_elem	*tmp;

	rotate = 0;
	tmp = (*stacks)->b;
	while (tmp->back->index != 0)
	{
		tmp = tmp->next;
		rotate++;
	}
	if (rotate > (*stacks)->qnty_b - rotate)
		rotate = rotate - (*stacks)->qnty_b;
	while ((*stacks)->b->back->index != 0)
	{
		if (rotate > 0)
			ft_ra_rb(stacks, (*stacks)->b->name);
		else
			ft_rra_rrb(stacks, (*stacks)->b->name);
	}
}

void			ft_get_stack_back(t_st **stacks)
{
	ft_move_first_elem_on_top_b(stacks);
	ft_print_stack_step(*stacks);
	while ((*stacks)->b)
		ft_pa_pb(stacks, (*stacks)->b->name);
}
