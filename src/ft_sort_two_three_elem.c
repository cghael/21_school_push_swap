/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two_three_elem.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:26:12 by cghael            #+#    #+#             */
/*   Updated: 2020/06/26 11:39:32 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_two_three_elem(t_st **stacks)
{
	t_elem *stack;

	if ((*stacks)->qnty_a > 3)
		return ;
	stack = (*stacks)->a;
	if ((*stacks)->qnty_a == 2 && stack->index > stack->next->index)
		ft_ra_rb(stacks, stack->name);
	if (NOT_SORTED == ft_check_stack_sorted((*stacks)->a, (*stacks)->qnty_a))
	{
		if (stack->index > stack->back->index && \
			stack->index < stack->next->index)
			ft_rra_rrb(stacks, stack->name);
		else if (stack->index > stack->back->index &&\
					stack->index > stack->next->index)
			ft_ra_rb(stacks, stack->name);
		else
			ft_sa_sb(stacks, stack->name);
	}
	if (NOT_SORTED == ft_check_stack_sorted((*stacks)->a, (*stacks)->qnty_a))
		ft_sort_two_three_elem(stacks);
}
