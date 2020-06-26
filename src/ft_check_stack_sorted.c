/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack_sorted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <cghael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:27:57 by cghael            #+#    #+#             */
/*   Updated: 2020/06/25 13:30:55 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	ft_stack_has_many_iters(t_elem *stack)
{
	t_elem *tmp;

	tmp = stack->back;
	if (stack->qnty > 2)
	{
		while (stack != tmp)
		{
			if (tmp->iter != stack->iter)
				return (1);
			stack = stack->next;
		}
	}
	return (0);
}
*/

int			ft_check_stack_sorted(t_elem *stack, int qnty)
{
	t_elem	*tmp;
	t_elem	*checked;

	tmp = stack;
	if (qnty < 2)
		return (SORTED);
	while (tmp->next != stack)
	{
		checked = tmp->next;
		if ((stack->name == 'a' && checked->value < tmp->value) \
				|| (stack->name == 'b' && checked->value > tmp->value))
			return (NOT_SORTED);
		tmp = tmp->next;
	}
	return (SORTED);
}
