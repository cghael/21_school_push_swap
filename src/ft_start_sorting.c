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

//static int		ft_find_piece(int qnty)
//{
//	if (qnty < 10)
//		return (qnty / 2);
//	if (qnty <= 50)
//		return (qnty / 3);
//	if (qnty <= 100)
//		return (qnty / 5);
//	if (qnty <= 300)
//		return (qnty / 8);
//	if (qnty <= 500)
//		return (qnty / 12);
//	if (qnty < 700)
//		return (qnty / 13);
//	return (qnty / 15);
//}

static int		ft_is_any_elem_to_push(t_elem *stack, int counter)
{
	while (counter)
	{
		if (stack->stay == 0)
			return (1);
		counter--;
		stack = stack->next;
	}
	return (0);
}

//static int		ft_is_any_elem_to_push(t_elem *stack, int piece)
//{
//	t_elem	*tmp;
//
//	if (!stack)
//		return (0);
//	tmp = stack->next;
//	if (stack->index < piece && stack->stay == 0)
//		return (1);
//	while (tmp != stack)
//	{
//		if (tmp->index < piece && tmp->stay == 0)
//			return (1);
//		tmp = tmp->next;
//	}
//	return (0);
//}

//static int		ft_rotate_side(t_elem *first, int piece)
//{
//	int		rotate;
//	int		reverse;
//	t_elem	*tmp;
//
//	rotate = 0;
//	reverse = 0;
//	tmp = first;
//	while (first->index >= piece || first->stay == 1)
//	{
//		first = first->next;
//		rotate++;
//	}
//	while (tmp->index >= piece || tmp->stay == 1)
//	{
//		tmp = tmp->back;
//		reverse++;
//	}
//	if (reverse < rotate)
//		return (-1);
//	return (1);
//}

//static void		ft_rotate_to_nearest_piece_elem(t_st **stacks, int piece)
//{
//	t_elem	*first;
//	int		rotate;
//
//	rotate = 0;
//	first = (*stacks)->a;
//	rotate = ft_rotate_side(first, piece);
////	while (first->index >= piece || first->stay == 1)
////	{
////		first = first->next;
////		rotate++;
////	}
////	if ((*stacks)->qnty_a - rotate < 0)
////		rotate = -rotate;
////	ft_print_stack_step(*stacks); //todo del
//	while ((*stacks)->a->index >= piece || (*stacks)->a->stay == 1)
//	{
//		if (rotate > 0)
//			ft_ra_rb(stacks, (*stacks)->a->name);
//		else
//			ft_rra_rrb(stacks, (*stacks)->a->name);
//	}
//}

void			ft_start_sorting(t_st **stacks)
{
	ft_presort_stack(stacks);
	while (ft_is_any_elem_to_push((*stacks)->a, (*stacks)->qnty_a))
	{
		if ((*stacks)->a->stay == 0)
			ft_pa_pb(stacks, (*stacks)->a->name);
		else
			ft_ra_rb(stacks, (*stacks)->a->name);
		ft_print_stack_step(*stacks); //todo del
	}
}

//void			ft_start_sorting(t_st **stacks)
//{
//	int		piece;
//	int		piece_step;
//	int		qnty;
////	int		max;
////	t_elem	*sorted_piece;
//
//	qnty = (*stacks)->qnty_a;
//	piece_step = ft_find_piece((*stacks)->qnty_a); //todo
//	piece = piece_step;
////	max = NOT_EXIST;
//	ft_presort_stack(stacks);
//	while ((*stacks)->a)
//	{
//		while (ft_is_any_elem_to_push((*stacks)->a, piece))
//		{
//			ft_move_elem_to_b(stacks, piece);
//			ft_print_stack_step(*stacks); //todo del
////			max = ft_presort_stack(stacks, &sorted_piece, max);
//		}
//		if (piece > qnty)
//			break ;
//		piece += piece_step;
//	}
//}
