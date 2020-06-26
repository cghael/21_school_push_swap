/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:44:31 by cghael            #+#    #+#             */
/*   Updated: 2020/06/26 13:44:36 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void		ft_add_elem_on_top(t_elem *tmp, t_elem **dst_stack, \
																t_st **stacks)
{
	if (*dst_stack)
	{
		tmp->next = *dst_stack;
		tmp->back = (*dst_stack)->back;
		tmp->back->next = tmp;
		(*dst_stack)->back = tmp;
		*dst_stack = tmp;
	}
	else
	{
		*dst_stack = tmp;
		tmp->next = tmp;
		tmp->back = tmp;
	}
	(*stacks)->qnty_b++;
}

static t_elem	*ft_delete_first_elem(t_elem **src_stack, t_st **stacks)
{
	t_elem *tmp;

	tmp = *src_stack;
	if ((*stacks)->qnty_a == 1)
		*src_stack = NULL;
	else
	{
		*src_stack = (*src_stack)->next;
		(*src_stack)->back = tmp->back;
		tmp->back->next = *src_stack;
	}
	tmp->next = NULL;
	tmp->back = NULL;
	(*stacks)->qnty_a--;
	return (tmp);
}

static void		ft_change_tmp_name(t_elem **tmp)
{
	if ((*tmp)->name == 'a')
		(*tmp)->name = 'b';
	else
		(*tmp)->name = 'a';
}

void			ft_pa_pb(t_st **stacks, char stack_name)
{
	t_elem	*tmp;

	if (stack_name == 'a')
	{
		if ((*stacks)->a)
		{
			tmp = ft_delete_first_elem(&(*stacks)->a, stacks);
			ft_change_tmp_name(&tmp);
			ft_add_elem_on_top(tmp, &(*stacks)->b, stacks);
		}
		ft_new_order_add(&(*stacks)->cmd, "_pb");
	}
	else
	{
		if ((*stacks)->b)
		{
			tmp = ft_delete_first_elem(&(*stacks)->b, stacks);
			ft_change_tmp_name(&tmp);
			ft_add_elem_on_top(tmp, &(*stacks)->a, stacks);
		}
		ft_new_order_add(&(*stacks)->cmd, "_pa");
	}
}
