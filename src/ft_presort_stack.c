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

//static void		ft_find_presort_piece(t_elem *stack, int qnty)
//{
//	t_elem	*tmp;
//	int		counter;
//
//	counter = qnty;
//	while (counter)
//	{
//		if (stack->index == 0)
//			break ;
//		stack = stack->next;
//		counter--;
//	}
//	tmp = stack;
//	tmp->stay = 1;
//	while (qnty)
//	{
//		stack = stack->next;
//		if (stack->index < tmp->index)
//		{
//			tmp = stack;
//			tmp->stay = 1;
//		}
//		qnty--;
//	}
//}
//
//static void	ft_new_stay_elems(t_elem **stack, int qnty, t_elem **sorted_piece)
//{
//	t_elem *tmp;
//
//	tmp = *stack;
//	while (qnty)
//	{
//		if (tmp->stay == 1)
//			tmp->stay = 0;
//		tmp = tmp->next;
//		qnty--;
//	}
//	tmp = *sorted_piece;
//	while (tmp->next->index - tmp->index == 1)
//	{
//		tmp->stay = 1;
//		tmp = tmp->next;
//	}
//	tmp->stay = 1;
//}

static void		ft_stay_max_stay(t_st **stacks, int max_index)
{
	int		n;
	t_elem	*tmp;

	tmp = (*stacks)->a;
	n = (*stacks)->qnty_a;
	while (n)
	{
		if (tmp->stay != max_index)
			tmp->stay = 0;
		n--;
		tmp = tmp->next;
	}
}

static int		ft_amount_of_index(t_elem *tmp, int n, int index)
{
	int counter;

	counter = 0;
	while (n)
	{
		if (tmp->stay == index)
		{
			counter++;
		}
		tmp = tmp->next;
		n--;
	}
	return (counter);
}

static void		ft_choose_biggest_index(t_st **stacks, int index)
{
	int		n;
	int		max;
	int		max_index;
	int		counter;
	t_elem	*tmp;

	max = 0;
	while (index > 0)
	{
//		n = (*stacks)->qnty_a;
//		tmp = (*stacks)->a;
//		counter = 0;
		counter = ft_amount_of_index((*stacks)->a, (*stacks)->qnty_a, index);
//		while (n)
//		{
//			if (tmp->stay == index)
//			{
//				counter++;
//			}
//			n--;
//		}
		if (counter > max)
		{
			max = counter;
			max_index = index;
		}
		index--;
	}
	ft_stay_max_stay(stacks, max_index);
}

static t_elem	*ft_any_elem_stay_zero(t_elem *stack, int qnty)
{
	while (qnty)
	{
		if (stack->stay == 0)
			return (stack);
		stack = stack->next;
		qnty--;
	}
	return (NULL);
}

void			ft_presort_stack(t_st **stacks)
{
	t_elem	*tmp;
	t_elem	*first;
	int		counter;
	int		index;

	index = 1;
	while ((first = ft_any_elem_stay_zero((*stacks)->a, (*stacks)->qnty_a)))
	{
		counter = (*stacks)->qnty_a;
		tmp = first;
		tmp->stay = index;
		while (counter)
		{
			first = first->next;
			if (first->stay == 0 && first->index > tmp->index)//todo if first 200 must find smaller too
			{
				tmp = first;
				tmp->stay = index;
			}
			counter--;
		}
		index++;
	}
	ft_choose_biggest_index(stacks, index - 1);
}
