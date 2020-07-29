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

void			ft_sort_stacks(t_st **stacks)
{
	if (NOT_SORTED == ft_check_stack_sorted((*stacks)->a, (*stacks)->qnty_a))
	{
		if ((*stacks)->qnty_a <= 3)
			ft_sort_two_three_elem(stacks);
		else
		{
			ft_start_sorting(stacks);
			if ((*stacks)->qnty_a == 3)
				ft_sort_two_three_elem(stacks);
			ft_get_stack_back(stacks);
		}
	}
}
