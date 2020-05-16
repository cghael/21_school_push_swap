//
// Created by Anton on 18.04.2020.
//

#include "push_swap.h"

int			ft_check_stack_sorted(t_elem *stack)
{
	t_elem	*tmp;
	t_elem	*checked;
	int		counter;

	tmp = stack;
	counter = stack->qnty;
	if (stack->qnty == 1)
		return (1);
	while (counter)
	{
		checked = tmp->next;
		while (checked != stack)
		{
			if ((stack->name == 'a' && checked->value < tmp->value) \
				|| (stack->name == 'b' && checked->value > tmp->value))
				return (STACK_NOT_SORTED);
			checked = checked->next;
		}
		tmp = tmp->next;
		counter--;
	}
	return (STACK_SORTED);
}
