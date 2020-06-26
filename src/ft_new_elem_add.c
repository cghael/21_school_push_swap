/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_elem_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:23:29 by cghael            #+#    #+#             */
/*   Updated: 2020/06/25 13:23:35 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_add_new_to_stack(t_elem **stack, t_elem *new)
{
	t_elem *tmp;
	int		counter;

	tmp = *stack;
	counter = 1;
	if (tmp == NULL)
	{
		*stack = new;
		(*stack)->back = *stack;
		(*stack)->next = *stack;
	}
	else
	{
		while (tmp->next != *stack)
		{
			counter++;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->back = tmp;
		new->next = *stack;
		(*stack)->back = new;
		new->index = counter;
	}
}

void		ft_new_elem_add(t_elem **stack, int numb)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (new == NULL)
	{
		ft_free_stack(*stack);
		ft_error_exit("Error malloc in ft_new_elem_add\n", new);
	}
	new->value = numb;
	new->next = NULL;
	new->back = NULL;
	new->index = 0;
	new->name = 'a';
	new->stay = 0;
	ft_add_new_to_stack(stack, new);
}
