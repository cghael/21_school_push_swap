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

static int	ft_count_rra_rb(t_st **stacks, t_elem *x, t_elem *y, t_steps **stp)
{
	int		counter_x;
	int		counter_y;
	t_elem	*tmp;

	counter_x = 0;
	counter_y = 0;
	tmp = (*stacks)->a;
	while (tmp != x)
	{
		counter_x++;
		tmp = tmp->back;
	}
	tmp = (*stacks)->b;
	while (tmp != y)
	{
		counter_y++;
		tmp = tmp->next;
	}
	return (counter_x + counter_y);
}

static int	ft_count_rra_rrb(t_st **stacks, t_elem *x, t_elem *y, t_steps **stp)
{
	int		counter_x;
	int		counter_y;
	t_elem	*tmp;

	counter_x = 0;
	counter_y = 0;
	tmp = (*stacks)->a;
	while (tmp != x)
	{
		counter_x++;
		tmp = tmp->back;
	}
	tmp = (*stacks)->b;
	while (tmp != y)
	{
		counter_y++;
		tmp = tmp->back;
	}
	if (counter_x > counter_y)
		return (counter_x);
	return (counter_y);
}

static int	ft_count_ra_rrb(t_st **stacks, t_elem *x, t_elem *y, t_steps **stp)
{
	int		counter_x;
	int		counter_y;
	t_elem	*tmp;

	counter_x = 0;
	counter_y = 0;
	tmp = (*stacks)->a;
	while (tmp != x)
	{
		counter_x++;
		ft_new_order_add((*stp)->var[i]->cm_line, "ra");
		tmp = tmp->next;
	}
	tmp = (*stacks)->b;
	while (tmp != y)
	{
		counter_y++;
		tmp = tmp->back;
	}
	return (counter_x + counter_y);
}

static int	ft_count_ra_rb(t_st **stacks, t_elem *x, t_elem *y, t_steps **stp)
{
	int		counter_x;
	int		counter_y;
	t_elem	*tmp;

	counter_x = 0;
	counter_y = 0;
	tmp = (*stacks)->a;
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

void		ft_count_steps(t_steps **stp, t_st **stacks)
{
	(*stp)->var[0].size = ft_count_ra_rb(stacks, (*stp)->x1, (*stp)->y1, stp);
	(*stp)->var[1].size = ft_count_ra_rb(stacks, (*stp)->x2, (*stp)->y2, stp);
	(*stp)->var[2].size = ft_count_ra_rrb(stacks, (*stp)->x1, (*stp)->y1, stp);
	(*stp)->var[3].size = ft_count_ra_rrb(stacks, (*stp)->x2, (*stp)->y2, stp);
	(*stp)->var[4].size = ft_count_rra_rrb(stacks, (*stp)->x1, (*stp)->y1, stp);
	(*stp)->var[5].size = ft_count_rra_rrb(stacks, (*stp)->x2, (*stp)->y2, stp);
	(*stp)->var[6].size = ft_count_rra_rb(stacks, (*stp)->x1, (*stp)->y1, stp);
	(*stp)->var[7].size = ft_count_rra_rb(stacks, (*stp)->x2, (*stp)->y2, stp);
}
