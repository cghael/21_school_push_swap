/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:53:17 by cghael            #+#    #+#             */
/*   Updated: 2020/07/14 14:53:23 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_find_piece(int qnty)
{
	if (qnty < 10)
		return (qnty / 2);
	if (qnty <= 50)
		return (qnty / 3);
	if (qnty <= 100)
		return (qnty / 5);
	if (qnty <= 300)
		return (qnty / 8);
	if (qnty <= 500)
		return (qnty / 11);
	if (qnty < 700)
		return (qnty / 13);
	return (qnty / 15);
}

static int		ft_is_any_elem_to_push(t_elem *stack, int piece)
{
	t_elem	*tmp;

	if (!stack)
		return (0);
	tmp = stack->next;
	if (stack->index < piece && stack->stay == 0)
		return (1);
	while (tmp != stack)
	{
		if (tmp->index < piece && tmp->stay == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			ft_start_sorting(t_st **stacks)
{
	int		piece;
	int		piece_step;
	int		qnty;

	qnty = (*stacks)->qnty_a;
	piece_step = ft_find_piece((*stacks)->qnty_a); //todo
	piece = piece_step;
	while ((*stacks)->a)
	{
		while (ft_is_any_elem_to_push((*stacks)->a, piece))
		{
			ft_move_elem_to_b(stacks, piece);
			ft_print_stack_step(*stacks); //todo del
		}
		if (piece > qnty)
			break ;
		piece += piece_step;
	}
}
