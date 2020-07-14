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

void		ft_move_elem_to_b(t_st **stacks, int piece)
{
	t_steps	*tmp;
	int		i;

	tmp = ft_choose_optimal_step(stacks, piece);
	ft_run_min_steps(tmp, stacks);
	i = 0;
	while (i < 8)
	{
		free(tmp->var[i]);
		i++;
	}
	free(tmp);
}