/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_steps_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:34:06 by cghael            #+#    #+#             */
/*   Updated: 2020/07/20 14:34:08 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_min_steps_count(t_steps **tmp)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	while (i < 4)
	{
		j = 0;
		counter = 0;
		while ((*tmp)->var[i][j])
		{
			if ((*tmp)->var[i][j] == '\n')
				counter++;
			j++;
		}
		if ((*tmp)->min_value == 0 || (*tmp)->min_value > counter)
		{
			(*tmp)->min_value = counter;
			(*tmp)->min_var = i;
		}
		i++;
	}
}
