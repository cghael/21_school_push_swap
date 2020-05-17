//
// Created by Anton on 18.04.2020.
//

#include "push_swap.h"

int		ft_check_stack_sorted(t_elem *stack, int move)
{
	t_elem	*tmp;
	t_elem	*checked;

	tmp = stack;
	if (stack->qnty == 1)
		return (1);
	while (move - 1)
	{
		checked = tmp->next;
		if ((stack->name == 'a' && checked->value < tmp->value) \
				|| (stack->name == 'b' && checked->value > tmp->value))
			return (STACK_NOT_SORTED);
		tmp = tmp->next;
		move--;
	}
	return (STACK_SORTED);
}
