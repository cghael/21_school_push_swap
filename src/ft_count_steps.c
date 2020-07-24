/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:46:40 by cghael            #+#    #+#             */
/*   Updated: 2020/07/13 14:43:28 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_count_ra_rrb(t_st **stacks, t_steps **stp)
{
	int		counter_x;
	int		counter_y;
	t_elem	*tmp;

	counter_x = 0;
	counter_y = 0;
	tmp = (*stacks)->a;
	while (tmp != (*stp)->y)
	{
		counter_x++;
		tmp = tmp->next;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->x)
	{
		counter_y++;
		tmp = tmp->back;
	}
	(*stp)->var[1] = counter_x + counter_y + 1;
}

static void	ft_count_rra_rb(t_st **stacks, t_steps **stp)
{
	int		counter_x;
	int		counter_y;
	t_elem	*tmp;

	counter_x = 0;
	counter_y = 0;
	tmp = (*stacks)->a;
	while (tmp != (*stp)->y)
	{
		counter_x++;
		tmp = tmp->back;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->x)
	{
		counter_y++;
		tmp = tmp->next;
	}
	(*stp)->var[3] = counter_x + counter_y + 1;
}

void		ft_count_steps(t_steps **stp, t_st **stacks)
{
	ft_count_ra_rb(stacks, stp);
	ft_count_ra_rrb(stacks, stp);
	ft_count_rra_rrb(stacks, stp);
	ft_count_rra_rb(stacks, stp);
}
