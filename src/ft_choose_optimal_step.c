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

static t_steps		*ft_create_t_steps(t_st **stacks)
{
	t_steps	*tmp;

	tmp = ft_memalloc(sizeof(t_steps));
	if (tmp == NULL)
	{
		ft_free_push_swap_mem(*stacks);
		ft_error_exit("Error malloc in ft_create_t_steps\n", tmp);
	}
	tmp->x = NULL;
	tmp->y = NULL;
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
		if ((x_index < tmp->index && tmp->index < tmp->back->index) ||
			(x_index > tmp->index && tmp->index < tmp->back->index && \
			x_index > tmp->back->index) ||
			(x_index < tmp->index && x_index > tmp->back->index && \
			tmp->index > tmp->back->index))
			return (tmp);
		tmp = tmp->next;
		qnty--;
	}
	return (NULL);
}

static t_steps		*ft_cur_steps(t_elem *x, t_st **stacks, t_steps *tmp)
{
	tmp->x = x;
	tmp->y = ft_find_y(tmp->x->index, (*stacks)->a, (*stacks)->qnty_a);
	ft_count_steps(&tmp, stacks);
	ft_min_steps_count(&tmp);
	return (tmp);
}

static t_steps		*ft_min_steps_elem(t_st **stacks, int counter)
{
	t_steps	*tmp;
	t_elem	*cur;
	t_steps	*min_elem;
	int		min_steps;

	cur = (*stacks)->b;
	min_steps = 0;
	min_elem = NULL;
	while (counter)
	{
		tmp = ft_create_t_steps(stacks);
		tmp = ft_cur_steps(cur, stacks, tmp);
		if (tmp->min_value < min_steps || min_steps == 0)
		{
			if (min_elem)
				free(min_elem);
			min_steps = tmp->min_value;
			min_elem = tmp;
		}
		else
			free(tmp);
		cur = cur->next;
		counter--;
	}
	return (min_elem);
}

t_steps*			ft_choose_optimal_step(t_st **stacks)
{
	t_steps	*tmp;

	tmp = ft_min_steps_elem(stacks, (*stacks)->qnty_b);
	return (tmp);
}
