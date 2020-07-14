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
	ft_print_stack_step(*stacks); //TODO del
	if (NOT_SORTED == ft_check_stack_sorted((*stacks)->a, (*stacks)->qnty_a))
	{

		ft_putstr("NOT_SORTED\n\n"); //TODO del
		if ((*stacks)->qnty_a <= 3)
			ft_sort_two_three_elem(stacks);
		else
		{
			//todo presort
			ft_start_sorting(stacks);
			ft_get_stack_back(stacks);
		}
	}
	else
		ft_putstr("SORTED!!!\n\n"); //TODO del
	ft_print_stack_step(*stacks); //TODO del
}