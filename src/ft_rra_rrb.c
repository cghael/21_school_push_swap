/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:22:11 by cghael            #+#    #+#             */
/*   Updated: 2020/06/23 13:22:19 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rra_rrb(t_st **stacks, char stack_name)
{
	if (stack_name == 'a')
	{
		if ((*stacks)->a)
			(*stacks)->a = (*stacks)->a->back;
		ft_new_order_add(&(*stacks)->cmd, "rra");
	}
	else
	{
		if ((*stacks)->b)
			(*stacks)->b = (*stacks)->b->back;
		ft_new_order_add(&(*stacks)->cmd, "rrb");
	}
}
