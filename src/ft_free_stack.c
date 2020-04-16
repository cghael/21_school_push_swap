//
// Created by Anton Gorobets on 16.04.20.
//

#include "push_swap.h"

void		ft_free_stack(t_elem *stack)
{
	t_elem	*tmp;

	tmp = stack->back;
	tmp->next = NULL;
	free(tmp);
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}