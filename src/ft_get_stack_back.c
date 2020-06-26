//
// Created by Anton on 26.06.2020.
//

#include "push_swap.h"

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

static void		ft_push_tmp_to_a(t_st **stacks, t_elem *tmp)
{
	//todo remember about rotate side
}

void			ft_get_stack_back(t_st **stacks)
{
	t_elem	*tmp;

	while ((*stacks)->b != NULL)
	{
		tmp = ft_find_best_next_push(*stacks);
		ft_push_tmp_to_a(stacks, tmp);
	}
}