//
// Created by Anton on 27.06.2020.
//

#include "push_swap.h"

int		ft_steps_ready_stack_a_to_push_current(t_elem *cur, t_st *stacks)
{
	int		r_steps;
	int		biggest;
	t_elem	*tmp;

	biggest = stacks->qnty_a + stacks->qnty_b - 1;
	r_steps = 1;
	tmp = stacks->a->next;
	if (cur->index != 0 && stacks->a->index > cur->index && \
	(stacks->a->back->index < cur->index || stacks->a->back->index == biggest))
		return (0);
	if (cur->index == 0 && stacks->a->back->index == biggest)
		return (0);
	while (tmp != stacks->a)
	{
		if (cur->index == 0 && tmp->back->index == biggest)
			break ;
		if (cur->index != 0 && tmp->index > cur->index && \
		(tmp->back->index < cur->index || tmp->back->index == biggest))
			break ;
		tmp = tmp->next;
		r_steps++;
	}
	if (r_steps <= stacks->qnty_a - r_steps)
		return (r_steps);
	return (r_steps - stacks->qnty_a);
}