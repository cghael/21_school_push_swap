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

static void		ft_write_steps(int counter_x, int counter_y, t_steps **stp)
{
	int rr_steps;

	if (counter_x >= counter_y)
	{
		rr_steps = counter_y;
		while (counter_x - counter_y)
		{
			(*stp)->var[0] = ft_strjoin((*stp)->var[0], "rb\n");
			counter_x--;
		}
	}
	else
	{
		rr_steps = counter_x;
		while (counter_y - counter_x)
		{
			(*stp)->var[0] = ft_strjoin((*stp)->var[0], "ra\n");
			counter_y--;
		}
	}
	while (rr_steps)
	{
		(*stp)->var[0] = ft_strjoin((*stp)->var[0], "rr\n");
		rr_steps--;
	}
}

void			ft_count_ra_rb(t_st **stacks, t_steps **stp)
{
	int		counter_x;
	int		counter_y;
	t_elem	*tmp;

	counter_x = 0;
	counter_y = 0;
	tmp = (*stacks)->a;
	while (tmp != (*stp)->y)
	{
		counter_y++;
		tmp = tmp->next;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->x)
	{
		counter_x++;
		tmp = tmp->next;
	}
	ft_write_steps(counter_x, counter_y, stp);
	(*stp)->var[0] = ft_strjoin((*stp)->var[0], "pb\n");
}