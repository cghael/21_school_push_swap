//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

static void		ft_change_qnty(t_elem **stack, int sign)
{
	int		qnty;
	t_elem	*tmp;

	tmp = *stack;
	qnty = (*stack)->qnty + sign;
	while (qnty)
	{
		tmp->qnty += sign;
		tmp = tmp->next;
		qnty--;
	}
}

static void		ft_add_elem_on_top(t_elem *tmp, t_elem **dst_stack)
{
	if (*dst_stack)
	{
		tmp->qnty = (*dst_stack)->qnty;
		tmp->next = *dst_stack;
		tmp->back = (*dst_stack)->back;
		tmp->back->next = tmp;
		(*dst_stack)->back = tmp;
		if ((*dst_stack)->iter == tmp->iter) //todo wrong when back
			ft_change_qnty(dst_stack, +1);
		else
			tmp->qnty++;
		*dst_stack = tmp;
	}
	else
	{
		tmp->qnty++;
		*dst_stack = tmp;
		tmp->next = tmp;
		tmp->back = tmp;
	}
}

static t_elem	*ft_delete_first_elem(t_elem **src_stack)
{
	t_elem *tmp;

	tmp = *src_stack;
	if ((*src_stack)->qnty == 1 && (*src_stack)->iter == (*src_stack)->next->iter)
		*src_stack = NULL;
	else
	{
		*src_stack = (*src_stack)->next;
		(*src_stack)->back = tmp->back;
		tmp->back->next = *src_stack;
		ft_change_qnty(src_stack, -1);
	}
	tmp->next = NULL;
	tmp->back = NULL;
	tmp->qnty = 0;
	return (tmp);
}

static void		ft_change_tmp_name(t_elem **tmp)
{
	if ((*tmp)->name == 'a')
		(*tmp)->name = 'b';
	else
		(*tmp)->name = 'a';
}

void			ft_pa_pb(t_order **cmd_stack, t_elem **src_stack, \
															t_elem **dst_stack)
{
	t_elem *tmp; //todo must know, is it get back or push forward recursion

	if (*src_stack)
	{
		tmp = ft_delete_first_elem(src_stack);
		ft_change_tmp_name(&tmp);
		ft_add_elem_on_top(tmp, dst_stack);
	}
	if (*src_stack)
	{
		if ((*src_stack)->name == 'b')
			ft_new_order_add(cmd_stack, "_pa");
		else
			ft_new_order_add(cmd_stack, "_pb");
	}
	else
	{
		if ((*dst_stack)->name == 'b')
			ft_new_order_add(cmd_stack, "_pb");
		else
			ft_new_order_add(cmd_stack, "_pa");
	}
}