/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:33:29 by cghael            #+#    #+#             */
/*   Updated: 2020/06/23 13:33:35 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_top_two_elem(t_elem **stack)
{
	t_elem	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next->back = *stack;
	tmp->next = *stack;
	tmp->back = (*stack)->back;
	(*stack)->back->next = tmp;
	(*stack)->back = tmp;
	*stack = tmp;
}

void		ft_sa_sb(t_st **stacks, char stack_name)
{
	if (stack_name == 'a')
	{
		ft_swap_top_two_elem(&(*stacks)->a);
		ft_new_order_add(&(*stacks)->cmd, "_sa");
	}
	else
	{
		ft_swap_top_two_elem(&(*stacks)->b);
		ft_new_order_add(&(*stacks)->cmd, "_sb");
	}
}
