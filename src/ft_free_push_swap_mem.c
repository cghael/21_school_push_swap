/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_push_swap_mem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:27:02 by cghael            #+#    #+#             */
/*   Updated: 2020/07/13 12:27:06 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_push_swap_mem(t_st *stacks)
{
	if (stacks)
	{
		if (stacks->a)
			ft_free_stack(stacks->a);
		if (stacks->b)
			ft_free_stack(stacks->b);
		if (stacks->cmd)
			ft_free_cmd_stack(stacks->cmd);
	}
	free(stacks);
}
