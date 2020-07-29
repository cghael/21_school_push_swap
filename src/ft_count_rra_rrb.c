/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_rra_rrb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:16:06 by cghael            #+#    #+#             */
/*   Updated: 2020/07/14 11:16:12 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_count_rra_rrb(t_st **stacks, t_steps **stp)
{
	int		counter_a;
	int		counter_b;
	t_elem	*tmp;

	counter_a = 0;
	counter_b = 0;
	tmp = (*stacks)->a;
	while (tmp != (*stp)->y)
	{
		counter_a++;
		tmp = tmp->back;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->x)
	{
		counter_b++;
		tmp = tmp->back;
	}
	if (counter_a >= counter_b)
		(*stp)->var[2] = counter_a + 1;
	else
		(*stp)->var[2] = counter_b + 1;
}
