/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_elem_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:18:54 by cghael            #+#    #+#             */
/*   Updated: 2020/06/30 15:39:30 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_move_elem_to_b(t_st **stacks, int piece)
{

	ft_move_elem_on_top_a();
	ft_ready_b_to_push_from_a();
//	t_elem	*tmp;
//
//	while ((*stacks)->a != NULL)
//	{
//		tmp = ft_find_best_next_push(*stacks);
//		ft_push_tmp_to_a(stacks, tmp);
//		ft_print_stack_step(*stacks); //todo del
//	}
//	ft_move_first_elem_on_top_a(stacks);
}