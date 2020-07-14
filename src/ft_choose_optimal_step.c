/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_optimal_step.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:55:48 by cghael            #+#    #+#             */
/*   Updated: 2020/07/13 14:27:18 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_steps		*ft_create_t_steps(void)
{
	t_steps	*tmp;

	tmp = ft_memalloc(sizeof(t_steps));
	if (tmp == NULL)
		return (NULL);
	tmp->x1 = NULL;
	tmp->y1 = NULL;
	tmp->x2 = NULL;
	tmp->y2 = NULL;
	return (tmp);
}

static t_elem		*ft_find_y(int x_index, t_elem *stack, int qnty)
{
	t_elem	*tmp;

	tmp = stack;
	if (qnty < 2)
		return (tmp);
	while (qnty)
	{
		if ((x_index > tmp->index && x_index < tmp->back->index) ||
			(x_index > tmp->index && tmp->index > tmp->back->index) ||
			(x_index < tmp->index && x_index < tmp->back->index && \
			tmp->index > tmp->back->index))
			return (tmp);
		tmp = tmp->next;
		qnty--;
	}
	return (NULL);
}

static void			ft_find_x2_y2(t_steps **tmp, t_st **stacks, int piece)
{
	(*tmp)->x2 = (*stacks)->a->back;
	while ((*tmp)->x2->index >= piece || (*tmp)->x2->stay == 1)
		(*tmp)->x2 = (*tmp)->x2->back;
	if ((*tmp)->x2 == (*tmp)->x1)
	{
		(*tmp)->x2 = NULL;
		return ;
	}
	(*tmp)->y2 = ft_find_y((*tmp)->x2->index, (*stacks)->b, (*stacks)->qnty_b);
}

static void			ft_find_x1_y1(t_steps **tmp, t_st **stacks, int piece)
{
	(*tmp)->x1 = (*stacks)->a;
	while ((*tmp)->x1->index >= piece || (*tmp)->x1->stay == 1)
		(*tmp)->x1 = (*tmp)->x1->next;
	(*tmp)->y1 = ft_find_y((*tmp)->x1->index, (*stacks)->b, (*stacks)->qnty_b);
}

t_steps*			ft_choose_optimal_step(t_st **stacks, int piece)
{
	t_steps	*tmp;

	tmp = ft_create_t_steps();
	if (tmp == NULL)
	{
		ft_free_push_swap_mem(*stacks);
		ft_error_exit("Error malloc in ft_choose_optimal_step\n", tmp);
	}
	ft_find_x1_y1(&tmp, stacks, piece);
	ft_find_x2_y2(&tmp, stacks, piece);
	ft_count_steps(&tmp, stacks);
	return (tmp);//todo del
}
