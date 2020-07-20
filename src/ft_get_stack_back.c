/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:54:41 by cghael            #+#    #+#             */
/*   Updated: 2020/07/14 14:54:47 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_move_first_elem_on_top_a(t_st **stacks)
{
	int		n;
	t_elem	*tmp;

	n = (*stacks)->qnty_a;
	tmp = (*stacks)->a;
	while (n)
	{
		if (tmp->index == 0)
			break ;
		tmp = tmp->next;
		n--;
	}
	if (n < (*stacks)->qnty_a - n)
	{
		while ((*stacks)->a->index != 0)
		{
			ft_rra_rrb(stacks, (*stacks)->a->name);
			ft_print_stack_step(*stacks);//todo del
		}
	}
	else
	{
		while ((*stacks)->a->index != 0)
		{
			ft_ra_rb(stacks, (*stacks)->a->name);
			ft_print_stack_step(*stacks);//todo del
		}
	}
}

static void		ft_move_stack_a_min_elem_top(t_st **stacks)
{
	int		n;
	t_elem	*tmp;

	n = (*stacks)->qnty_a;
	tmp = (*stacks)->a;
	while (n)
	{
		if (tmp->index > (*stacks)->b->index && \
			tmp->back->index < (*stacks)->b->index)
			break ;
		tmp = tmp->next;
		n--;
	}
	if (n < (*stacks)->qnty_a - n)
	{
		while ((*stacks)->a->index < (*stacks)->b->index)
		{
			ft_rra_rrb(stacks, (*stacks)->a->name);
			ft_print_stack_step(*stacks);//todo del
		}
	}
	else
	{
		while ((*stacks)->a->index < (*stacks)->b->index)
		{
			ft_ra_rb(stacks, (*stacks)->a->name);
			ft_print_stack_step(*stacks);//todo del
		}
	}
}

static void		ft_move_first_elems_on_stacks_top(t_st **stacks)
{

}

static void		ft_move_first_elem_on_top_b(t_st **stacks)
{
	int		rotate;
	t_elem	*tmp;

	rotate = 0;
	tmp = (*stacks)->b;
	while (tmp->index < tmp->back->index || tmp->index < tmp->next->index)
	{
		tmp = tmp->next;
		rotate++;
	}
	if (rotate > (*stacks)->qnty_b - rotate)
		rotate = rotate - (*stacks)->qnty_b;
	while ((*stacks)->b->index < (*stacks)->b->back->index ||
			(*stacks)->b->index < (*stacks)->b->next->index)
	{
		if (rotate > 0)
			ft_ra_rb(stacks, (*stacks)->b->name);
		else
			ft_rra_rrb(stacks, (*stacks)->b->name);
	}
}

void			ft_get_stack_back(t_st **stacks)
{
	ft_move_first_elems_on_stacks_top(stacks);
	ft_print_stack_step(*stacks);
	while ((*stacks)->b)
	{
		if ((*stacks)->b->index > (*stacks)->a->index && \
			(*stacks)->b->index < (*stacks)->a->back->index)
		{
			ft_print_stack_step(*stacks);
			ft_move_stack_a_min_elem_top(stacks);
		}
		ft_pa_pb(stacks, (*stacks)->b->name);
	}
	ft_move_first_elem_on_top_a(stacks);
//		ft_pa_pb(stacks, (*stacks)->b->name);
}
