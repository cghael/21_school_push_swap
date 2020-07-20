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
		(*stp)->var[1] = ft_strjoin((*stp)->var[1], "ra\n");
		tmp = tmp->next;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->x)
	{
		counter_y++;
		(*stp)->var[1] = ft_strjoin((*stp)->var[1], "rrb\n");
		tmp = tmp->back;
	}
	(*stp)->var[1] = ft_strjoin((*stp)->var[1], "pb\n");
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
		(*stp)->var[3] = ft_strjoin((*stp)->var[3], "rra\n");
		tmp = tmp->back;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->x)
	{
		counter_y++;
		(*stp)->var[3] = ft_strjoin((*stp)->var[3], "rb\n");
		tmp = tmp->next;
	}
	(*stp)->var[3] = ft_strjoin((*stp)->var[3], "pb\n");
}

void		ft_count_steps(t_steps **stp, t_st **stacks)
{
	ft_count_ra_rb(stacks, stp);
	ft_count_ra_rrb(stacks, stp);
	ft_count_rra_rrb(stacks, stp);
	ft_count_rra_rb(stacks, stp);
}
