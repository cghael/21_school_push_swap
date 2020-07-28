/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:30:13 by cghael            #+#    #+#             */
/*   Updated: 2020/07/17 12:30:15 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_mark_last_three(t_st **stacks)
{
	int		counter;
	t_elem	*tmp;

	tmp = (*stacks)->a;
	counter = (*stacks)->qnty_a;
	while (counter)
	{
		if (tmp->index >= (*stacks)->qnty_a - 3)
			tmp->stay = 1;
		tmp = tmp->next;
		counter--;
	}
}

static void	ft_mark_index(t_st **stacks, t_elem *first)
{
	t_elem	*tmp;
	t_elem	*last;
	int		counter;

	counter = (*stacks)->qnty_a;
	tmp = (*stacks)->a;
	while (tmp != first)
		tmp = tmp->next;
	last = tmp;
	last->stay = 1;
	while (counter)
	{
		if (tmp->index > last->index)
		{
			last = tmp;
			last->stay = 1;
		}
		tmp = tmp->next;
		counter--;
	}
}

static int	ft_find_sequence(t_elem *first, int qnty)
{
	t_elem	*tmp;
	t_elem	*last;
	int		sqnce;

	tmp = first->next;
	last = first;
	sqnce = 0;
	while (qnty)
	{
		if (tmp->index > last->index)
		{
			last = tmp;
			sqnce++;
		}
		tmp = tmp->next;
		qnty--;
	}
	return (sqnce);
}

void			ft_presort_stack(t_st **stacks)
{
	t_elem	*sqnce_first;
	t_elem	*first;
	int		counter;
	int		sqnce;
	int		max_sqnce;

	counter = (*stacks)->qnty_a;
	first = (*stacks)->a;
	max_sqnce = 0;
	while (counter)
	{
		sqnce = ft_find_sequence(first, (*stacks)->qnty_a);
		if (sqnce > max_sqnce)
		{
			max_sqnce = sqnce;
			sqnce_first = first;
		}
		first = first->next;
		counter--;
	}
	if (max_sqnce > 2)
		ft_mark_index(stacks, sqnce_first);
	else
		ft_mark_last_three(stacks);
}
