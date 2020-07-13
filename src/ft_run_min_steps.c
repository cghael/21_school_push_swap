/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_min_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:10:41 by cghael            #+#    #+#             */
/*   Updated: 2020/07/13 14:43:28 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		*ft_choose_min_steps(t_steps *tmp)
{
	t_arr_elem	*min;

	min = ft_arr_min(tmp->var, 8);
}

void			ft_run_min_steps(t_steps *tmp, t_st **stacks)
{
	char *cmd_str;

	cmd_str = ft_choose_min_steps(tmp);
}
