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

static void		ft_move_stack_a_min_elem_top(t_st **stacks)
{
	int		n;
	t_elem	*tmp;

	n = (*stacks)->qnty_a;
	tmp = (*stacks)->a;
	while (n)
	{
		if (tmp->index == 0)
			break ;
		tmp = tmp->next;
		n--;
	}
	if (n < (*stacks)->qnty_a - n)
	{
		while ((*stacks)->a->index != 0)
			ft_rra_rrb(stacks, (*stacks)->a->name);
	}
	else
	{
		while ((*stacks)->a->index != 0)
			ft_ra_rb(stacks, (*stacks)->a->name);
	}
}

void			ft_get_stack_back(t_st **stacks)
{
	t_steps	*tmp;

	while ((*stacks)->b)
	{
		tmp = ft_choose_optimal_step(stacks);
		ft_create_cmd(tmp, stacks);
	}
	ft_move_stack_a_min_elem_top(stacks);
}
