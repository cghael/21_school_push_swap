/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_elem_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:18:54 by cghael            #+#    #+#             */
/*   Updated: 2020/07/13 13:15:40 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void			ft_find_x1_y1(t_steps **tmp, t_st **stacks, int piece)
//{
//
//}
//
//static t_steps*		ft_choose_optimal_step(t_st **stacks, int piece)
//{
//	t_steps	*tmp;
//
//	tmp = malloc(sizeof(t_steps));
//	if (tmp == NULL)
//		ft_error_exit("Error malloc in ft_choose_optimal_step\n", *stacks);  //todo del stacks
//	ft_find_x1_y1(&tmp, stacks, piece);
//	ft_find_x2_y2(&tmp, stacks, piece);
//}

void		ft_move_elem_to_b(t_st **stacks, int piece)
{
	t_steps *tmp;

	tmp = ft_choose_optimal_step(stacks, piece);
	ft_run_min_steps(tmp, stacks);
//	ft_move_elem_on_top_a();
//	ft_ready_b_to_push_from_a();






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