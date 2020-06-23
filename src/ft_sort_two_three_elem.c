/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two_three_elem.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:26:12 by cghael            #+#    #+#             */
/*   Updated: 2020/06/23 13:22:01 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_two_three_elem(t_st **stacks, char stack_name)
{
	t_elem *stack;

	stack = (stack_name == 'a') ? (*stacks)->a : (*stacks)->b;
	if (stack->qnty == 2 && stack->index > stack->next->index)
		ft_ra_rb(stacks, stack_name);
	if (STACK_NOT_SORTED == ft_check_stack_sorted(stack, stack->qnty))
	{
		if (stack->index > stack->back->index && \
			stack->index < stack->next->index)
			ft_rra_rrb(stacks, stack_name);
		else if (stack->index > stack->back->index &&\
					stack->index > stack->next->index)
			ft_ra_rb(stacks, stack_name);
		else
			ft_sa_sb(stacks, stack_name);
	}
	if (STACK_NOT_SORTED == ft_check_stack_sorted(stack, stack->qnty))
		ft_sort_two_three_elem(stacks, stack_name);
}