//
// Created by Anton on 26.06.2020.
//

#include "push_swap.h"

static int		ft_need_steps_to_push(t_elem *current, t_st *stacks)
{
	int	counter;

	counter = ft_abs(ft_steps_to_move_current_on_top_b(current, stacks));
	counter += ft_abs(ft_steps_ready_stack_a_to_push_current(current, stacks));
	return (counter);
}

static t_elem	*ft_find_best_next_push(t_st *stacks)
{
	t_elem	*tmp;
	t_elem	*best_elem;
	int		min_steps;
	int		cur_steps;

	tmp = stacks->b->next;
	min_steps = ft_need_steps_to_push(stacks->b, stacks);
	best_elem = stacks->b;
	while (tmp != stacks->b)
	{
		cur_steps = ft_need_steps_to_push(tmp, stacks);
		if (cur_steps < min_steps)
		{
			min_steps = cur_steps;
			best_elem = tmp;
		}
		tmp = tmp->next;
	}
	return (best_elem);
}

static void		ft_move_first_elem_on_top_a(t_st **stacks)
{
	int		rotate;
	t_elem	*tmp;

	rotate = 0;
	tmp = (*stacks)->a;
	while (tmp->index != 0)
	{
		tmp = tmp->next;
		rotate++;
	}
	if (rotate > (*stacks)->qnty_a - rotate)
		rotate = rotate - (*stacks)->qnty_a;
	while ((*stacks)->a->index != 0)
	{
		if (rotate > 0)
			ft_ra_rb(stacks, (*stacks)->a->name);
		else
			ft_rra_rrb(stacks, (*stacks)->a->name);
	}
}

void			ft_get_stack_back(t_st **stacks)
{
	t_elem	*tmp;

	while ((*stacks)->b != NULL)
	{
		tmp = ft_find_best_next_push(*stacks);
		ft_push_tmp_to_a(stacks, tmp);
		ft_print_stack_step(*stacks); //todo del
	}
	ft_move_first_elem_on_top_a(stacks);
}