/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <cghael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:04:30 by cghael            #+#    #+#             */
/*   Updated: 2020/06/26 13:54:02 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int		ft_find_presort_piece(t_elem *stack, int qnty, t_elem **fin)
//{
//	t_elem	*tmp;
////	t_elem	*fin;
//	int		counter;
//	int		max;
//
//	counter = 0;
//	max = 0;
//	tmp = stack;
//	while (qnty)
//	{
//		if (tmp->index - tmp->back->index == 1)
//			counter++;
//		else if (tmp->index - tmp->back->index != 1 && counter > 0)
//		{
//			if (max < counter)
//			{
//				*fin = tmp->back;
//				max = counter;
//			}
//			counter = 0;
//		}
//		tmp = tmp->next;
//		qnty--;
//	}
//	return (max);
//}
//
//static void		ft_presort_stack(t_st **stacks)
//{
//	int		n;
//	int		max;
//	t_elem	*tmp;
//	t_elem	*fin;
//
//	max = ft_find_presort_piece((*stacks)->a, (*stacks)->qnty_a, &fin);
//	if (max == 0)
//	{
//		tmp = (*stacks)->a;
//		n = (*stacks)->qnty_a;
//		while (n)
//		{
//			if (tmp->index >= (*stacks)->qnty_a - 3)
//				tmp->stay = 1;
//			tmp = tmp->next;
//			n--;
//		}
//	}
//}

void			ft_sort_stacks(t_st **stacks)
{
	ft_print_stack_step(*stacks); //TODO del
	if (NOT_SORTED == ft_check_stack_sorted((*stacks)->a, (*stacks)->qnty_a))
	{

		ft_putstr("NOT_SORTED\n\n"); //TODO del
		if ((*stacks)->qnty_a <= 3)
			ft_sort_two_three_elem(stacks);
		else
		{
//			ft_presort_stack(stacks);
			ft_start_sorting(stacks);
//			ft_sort_two_three_elem(stacks);
			ft_get_stack_back(stacks);
		}
		ft_print_stack_step(*stacks); //TODO del
	}
	else
		ft_putstr("SORTED!!!\n\n"); //TODO del
	ft_print_stack_step(*stacks); //TODO del
}