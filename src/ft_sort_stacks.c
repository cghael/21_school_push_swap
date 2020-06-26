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

static void		ft_move_elem_to_b(t_st **stacks, int piece)
{
	if (ROTATE == ft_find_rotate_side((*stacks)->a, piece))
	{
		while ((*stacks)->a->index >= piece)
			ft_ra_rb(stacks, (*stacks)->a->name);
	}
	else
	{
		while ((*stacks)->a->index >= piece)
			ft_rra_rrb(stacks, (*stacks)->a->name);
	}
	ft_pa_pb(stacks, (*stacks)->a->name);
}

static void		ft_start_sorting(t_st **stacks)
{
	int	piece;
	int	qnty;
	int	i;

	i = 0;
	qnty = (*stacks)->qnty_a;
//	piece = ft_find_piece((*stacks)->qnty_a); //todo
	piece = 5;
	while (piece <= qnty && (*stacks)->a != NULL)
	{
		while (i < piece)
		{
			ft_move_elem_to_b(stacks, piece);
			ft_print_stack_step(*stacks); //todo del
			i++;
		}
		piece += piece;
	}
}

void			ft_sort_stacks(t_st **stacks)
{
	ft_print_stack_step(*stacks); //TODO del

	if (NOT_SORTED == ft_check_stack_sorted((*stacks)->a, (*stacks)->qnty_a))
	{

		ft_putstr("NOT_SORTED\n\n"); //TODO del
		if ((*stacks)->qnty_a <= 3)
			ft_sort_two_three_elem(stacks);
		else
			ft_start_sorting(stacks);
	}
	else
		ft_putstr("SORTED!!!\n\n"); //TODO del
	ft_print_stack_step(*stacks); //TODO del
}