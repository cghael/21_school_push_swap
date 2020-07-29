/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:53:17 by cghael            #+#    #+#             */
/*   Updated: 2020/07/14 14:53:23 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_is_any_elem_to_push(t_elem *stack, int counter)
{
	while (counter)
	{
		if (stack->stay == 0)
			return (1);
		counter--;
		stack = stack->next;
	}
	return (0);
}

void			ft_start_sorting(t_st **stacks)
{
	ft_presort_stack(stacks);
	while (ft_is_any_elem_to_push((*stacks)->a, (*stacks)->qnty_a))
	{
		if ((*stacks)->a->stay == 0)
			ft_pa_pb(stacks, (*stacks)->a->name);
		else
			ft_ra_rb(stacks, (*stacks)->a->name);
	}
}
