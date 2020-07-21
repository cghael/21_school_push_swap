/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:57:50 by cghael            #+#    #+#             */
/*   Updated: 2020/07/21 12:57:54 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_stack(t_elem *stack)
{
	t_elem	*tmp;

	tmp = stack->back;
	tmp->next = NULL;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
