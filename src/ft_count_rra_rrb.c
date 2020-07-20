/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_rra_rrb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:16:06 by cghael            #+#    #+#             */
/*   Updated: 2020/07/14 11:16:12 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void		ft_write_steps(int counter_a, int counter_b, t_steps **stp)
//{
//	int rr_steps;
//
//	if (counter_a >= counter_b)
//	{
//		rr_steps = counter_b;
//		while (counter_a - counter_b)
//		{
//			(*stp)->var[2] = ft_strjoin((*stp)->var[2], "rra\n");
//			counter_a--;
//		}
//	}
//	else
//	{
//		rr_steps = counter_a;
//		while (counter_b - counter_a)
//		{
//			(*stp)->var[2] = ft_strjoin((*stp)->var[2], "rrb\n");
//			counter_b--;
//		}
//	}
//	while (rr_steps)
//	{
//		(*stp)->var[2] = ft_strjoin((*stp)->var[2], "rrr\n");
//		rr_steps--;
//	}
//}

void			ft_count_rra_rrb(t_st **stacks, t_steps **stp)
{
	int		counter_a;
	int		counter_b;
	t_elem	*tmp;

	counter_a = 0;
	counter_b = 0;
	tmp = (*stacks)->a;
	while (tmp != (*stp)->y)
	{
		counter_a++;
		tmp = tmp->back;
	}
	tmp = (*stacks)->b;
	while (tmp != (*stp)->x)
	{
		counter_b++;
		tmp = tmp->back;
	}
	if (counter_a >= counter_b)
		(*stp)->var[2] = counter_a + 1;
	else
		(*stp)->var[2] = counter_b + 1;
//	ft_write_steps(counter_a, counter_b, stp);
//	(*stp)->var[2] = ft_strjoin((*stp)->var[2], "pb\n");
}
