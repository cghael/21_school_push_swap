//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

static void		ft_add_elem_on_top(t_elem *tmp, t_elem **dst_stack)
{
	if (*dst_stack)
	{
		tmp->qnty = (*dst_stack)->qnty + 1;
		tmp->next = *dst_stack;
		tmp->back = (*dst_stack)->back;
		tmp->back->next = tmp;
		(*dst_stack)->back = tmp;
		(*dst_stack)->qnty = 0;
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
	if ((*src_stack)->qnty > 1)
	{
		*src_stack = (*src_stack)->next;
		(*src_stack)->back = tmp->back;
		tmp->back->next = *src_stack;
		(*src_stack)->qnty = tmp->qnty - 1;
	}
	else
		*src_stack = NULL;
	tmp->next = NULL;
	tmp->back = NULL;
	tmp->qnty = 0;
	return (tmp);
}

void			ft_pa_pb(t_order **cmd_stack, t_elem **src_stack, \
							t_elem **dst_stack, char dst_ch)
{
	t_elem *tmp;

	if (*src_stack)
	{
		tmp = ft_delete_first_elem(src_stack);
		ft_add_elem_on_top(tmp, dst_stack);
	}
	if (dst_ch == 'a')
		ft_new_order_add(cmd_stack, "_pa");
	else
		ft_new_order_add(cmd_stack, "_pb");
}