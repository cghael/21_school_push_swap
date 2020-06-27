//
// Created by Anton on 27.06.2020.
//

#include "push_swap.h"

int		ft_steps_to_move_current_on_top_b(t_elem *current, t_st *stacks)
{
	int		r_steps;
	int		rr_steps;
	t_elem	*tmp;
	int		qnty_stack;

	r_steps = 0;
	tmp = stacks->b;
	qnty_stack = stacks->qnty_b;
	if (current->name == 'a')
	{
		qnty_stack = stacks->qnty_a;
		tmp = stacks->a;
	}
	while (tmp != current)
	{
		tmp = tmp->next;
		r_steps++;
	}
	rr_steps = qnty_stack - r_steps;
	if (r_steps <= rr_steps)
		return (r_steps);
	return (-rr_steps);
}