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

static void		ft_write_steps(int counter_x, int counter_y, t_steps **stp, int p)
{
	int rr_steps;

	if (counter_x >= counter_y)
	{
		rr_steps = counter_y;
		while (counter_x - counter_y)
		{
			(*stp)->var[5 + p] = ft_strjoin((*stp)->var[5 + p], "rra\n");
			counter_x--;
		}
	}
	else
	{
		rr_steps = counter_x;
		while (counter_y - counter_x)
		{
			(*stp)->var[5 + p] = ft_strjoin((*stp)->var[5 + p], "rrb\n");
			counter_y--;
		}
	}
	while (rr_steps)
	{
		(*stp)->var[5 + p] = ft_strjoin((*stp)->var[5 + p], "rrr\n");
		rr_steps--;
	}
}

void			ft_count_rra_rrb(t_st **stacks, t_steps **stp, int point)
{
	int		counter_x;
	int		counter_y;
	t_elem	*tmp;

	counter_x = 0;
	counter_y = 0;
	tmp = (*stacks)->a;
	while (tmp != (*stp)->x1 && point == 1 || tmp != (*stp)->x2 && point == 2)
	{
		counter_x++;
		tmp = tmp->back;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->y1 && point == 1 || tmp != (*stp)->y2 && point == 2)
	{
		counter_y++;
		tmp = tmp->back;
	}
	ft_write_steps(counter_x, counter_y, stp, point);
	(*stp)->var[5 + point] = ft_strjoin((*stp)->var[5 + point], "pa\n");
}
