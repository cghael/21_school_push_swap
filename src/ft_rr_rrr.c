/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:30:08 by cghael            #+#    #+#             */
/*   Updated: 2020/07/13 14:30:11 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rr_rrr(t_st **stacks, int side)
{
	if (ROTATE == side)
	{
		if ((*stacks)->a)
			(*stacks)->a = (*stacks)->a->next;
		if ((*stacks)->b)
			(*stacks)->b = (*stacks)->b->next;
		ft_new_order_add(&(*stacks)->cmd, "rr");
	}
	else
	{
		if ((*stacks)->a)
			(*stacks)->a = (*stacks)->a->back;
		if ((*stacks)->b)
			(*stacks)->b = (*stacks)->b->back;
		ft_new_order_add(&(*stacks)->cmd, "rrr");
	}
}
