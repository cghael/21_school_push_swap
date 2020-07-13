/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_ra_rb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:03:05 by cghael            #+#    #+#             */
/*   Updated: 2020/07/13 16:03:07 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_ra_rb(t_st **stacks, t_steps **stp, int elem)
{
	int		counter_x;
	int		counter_y;
	t_elem	*tmp;

	counter_x = 0;
	counter_y = 0;
	tmp = (*stacks)->a;
	if (elem == 1)
		ft_count_first_elem((*stacks)->a, (*stp)->x1, (*stp)->var[])
	while (tmp != x)
	{
		counter_x++;
		tmp = tmp->next;
	}
	tmp = (*stacks)->b;
	while (tmp != y)
	{
		counter_y++;
		tmp = tmp->next;
	}
	if (counter_x > counter_y)
		return (counter_x);
	return (counter_y);
}