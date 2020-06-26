//
// Created by Anton on 26.06.2020.
//

#include "push_swap.h"

static int	ft_steps_ready_stack_a_to_push_current(t_elem *cur, t_st *stacks)
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
			return (r_steps);
		if (cur->index != 0 && tmp->index > cur->index && \
		(tmp->back->index < cur->index || tmp->back->index == biggest))
			return (r_steps);
		tmp = tmp->next;
		r_steps++;
	}
	return (-1);
}

static int	ft_steps_to_move_current_on_top_b(t_elem *current, t_st *stacks)
{
	int		r_steps;
	int		rr_steps;
	t_elem	*tmp;

	r_steps = 0;
	tmp = stacks->b;
	while (tmp != current)
	{
		tmp = tmp->next;
		r_steps++;
	}
	rr_steps = stacks->qnty_b - r_steps;
	if (r_steps <= rr_steps)
		return (r_steps);
	return (rr_steps);
}

int			ft_need_steps_to_push(t_elem *current, t_st *stacks)
{
	int	counter;

	counter = ft_steps_to_move_current_on_top_b(current, stacks);
	counter += ft_steps_ready_stack_a_to_push_current(current, stacks);
	return (counter);
}