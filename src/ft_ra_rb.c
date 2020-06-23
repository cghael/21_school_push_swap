/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:19:24 by cghael            #+#    #+#             */
/*   Updated: 2020/06/23 13:19:38 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_ra_rb(t_st **stacks, char stack_name)
{
	if (stack_name == 'a')
	{
		(*stacks)->a = (*stacks)->a->next;
		ft_new_order_add(&(*stacks)->cmd, "_ra");
	}
	else
	{
		(*stacks)->b = (*stacks)->b->next;
		ft_new_order_add(&(*stacks)->cmd, "_rb");
	}
}
