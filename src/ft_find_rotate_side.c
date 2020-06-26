/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_rotate_side.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:04:03 by cghael            #+#    #+#             */
/*   Updated: 2020/06/26 13:04:12 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_rotate_side(t_elem *stack, int piece)
{
	int		rr_counter;
	int		r_counter;
	t_elem	*tmp;

	tmp = stack;
	r_counter = 0;
	rr_counter = 0;
	while (tmp->index >= piece)
	{
		r_counter++;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp->index >= piece)
	{
		rr_counter++;
		tmp = tmp->back;
	}
	if (r_counter >= rr_counter)
		return (ROTATE);
	return (REVERSE);
}
