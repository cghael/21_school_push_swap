/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:54:51 by cghael            #+#    #+#             */
/*   Updated: 2020/07/21 12:54:55 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_create_rra_rb_cmd(t_steps *tmp, t_st **stacks)
{
	while (tmp->y != (*stacks)->a)
		ft_rra_rrb(stacks, (*stacks)->a->name);
	while (tmp->x != (*stacks)->b)
		ft_ra_rb(stacks, (*stacks)->b->name);
}

static void	ft_create_rra_rrb_cmd(t_steps *tmp, t_st **stacks)
{
	while ((*stacks)->a != tmp->y && (*stacks)->b != tmp->x)
		ft_rr_rrr(stacks, REVERSE);
	while ((*stacks)->a != tmp->y)
		ft_rra_rrb(stacks, (*stacks)->a->name);
	while ((*stacks)->b != tmp->x)
		ft_rra_rrb(stacks, (*stacks)->b->name);
}

static void	ft_create_ra_rrb_cmd(t_steps *tmp, t_st **stacks)
{
	while (tmp->y != (*stacks)->a)
		ft_ra_rb(stacks, (*stacks)->a->name);
	while (tmp->x != (*stacks)->b)
		ft_rra_rrb(stacks, (*stacks)->b->name);
}

static void	ft_create_ra_rb_cmd(t_steps *tmp, t_st **stacks)
{
	while ((*stacks)->a != tmp->y && (*stacks)->b != tmp->x)
		ft_rr_rrr(stacks, ROTATE);
	while ((*stacks)->a != tmp->y)
		ft_ra_rb(stacks, (*stacks)->a->name);
	while ((*stacks)->b != tmp->x)
		ft_ra_rb(stacks, (*stacks)->b->name);
}

void		ft_create_cmd(t_steps *tmp, t_st **stacks)
{
	if (tmp->min_var == 0)
		ft_create_ra_rb_cmd(tmp, stacks);
	else if (tmp->min_var == 1)
		ft_create_ra_rrb_cmd(tmp, stacks);
	else if (tmp->min_var == 2)
		ft_create_rra_rrb_cmd(tmp, stacks);
	else
		ft_create_rra_rb_cmd(tmp, stacks);
	ft_pa_pb(stacks, (*stacks)->b->name);
}
