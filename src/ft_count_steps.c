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

static void	ft_count_rra_rb(t_st **stacks, t_steps **stp, int point)
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
		(*stp)->var[3 + point] = \
							ft_strjoin((*stp)->var[3 + point], "rra\n");
		tmp = tmp->back;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->y1 && point == 1 || tmp != (*stp)->y2 && point == 2)
	{
		counter_y++;
		(*stp)->var[3 + point] = \
							ft_strjoin((*stp)->var[3 + point], "rb\n");
		tmp = tmp->next;
	}
	(*stp)->var[3 + point] = \
							ft_strjoin((*stp)->var[3 + point], "pa\n");
}

static void	ft_count_ra_rrb(t_st **stacks, t_steps **stp, int point)
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
		(*stp)->var[-1 + point] = \
							ft_strjoin((*stp)->var[-1 + point], "ra\n");
		tmp = tmp->next;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->y1 && point == 1 || tmp != (*stp)->y2 && point == 2)
	{
		counter_y++;
		(*stp)->var[-1 + point] = \
							ft_strjoin((*stp)->var[-1 + point], "rrb\n");
		tmp = tmp->back;
	}
	(*stp)->var[-1 + point] = \
							ft_strjoin((*stp)->var[-1 + point], "pa\n");
}

void		ft_count_steps(t_steps **stp, t_st **stacks)
{
	ft_count_ra_rb(stacks, stp, 1);
	if ((*stp)->x2)
		ft_count_ra_rb(stacks, stp, 2);
	ft_count_ra_rrb(stacks, stp, 1);
	if ((*stp)->x2)
		ft_count_ra_rrb(stacks, stp, 2);
	ft_count_rra_rrb(stacks, stp, 1);
	if ((*stp)->x2)
		ft_count_rra_rrb(stacks, stp, 2);
	ft_count_rra_rb(stacks, stp, 1);
	if ((*stp)->x2)
		ft_count_rra_rb(stacks, stp, 2);
}
