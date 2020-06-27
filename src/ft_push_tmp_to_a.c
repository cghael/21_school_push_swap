//
// Created by Anton on 27.06.2020.
//

#include "push_swap.h"

static int		ft_check_first_position(t_elem *cur, t_elem *stack, int biggest)
{
	if (cur->index != 0 && stack->index > cur->index && \
	(stack->back->index < cur->index || stack->back->index == biggest))
		return (0);
	if (cur->index == 0 && stack->back->index == biggest)
		return (0);
	return (1);
}

static void		ft_ready_stack_a_to_push(t_st **stacks, t_elem *cur)
{
	int	rotate;
	int	biggest;

	rotate = ROTATE;
	if (0 > ft_steps_ready_stack_a_to_push_current(cur, *stacks))
		rotate = REVERSE;
	biggest = (*stacks)->qnty_a + (*stacks)->qnty_b - 1;
	if (ft_check_first_position(cur, (*stacks)->a, biggest) == 0)
		return ;
	while (cur != (*stacks)->a)
	{
		if (cur->index == 0 && (*stacks)->a->back->index == biggest)
			return ;
		if (cur->index != 0 && (*stacks)->a->index > cur->index && \
		((*stacks)->a->back->index < cur->index || (*stacks)->a->back->index == biggest))
			return ;
		if (rotate > 0)
			ft_ra_rb(stacks, (*stacks)->a->name);
		else
			ft_rra_rrb(stacks, (*stacks)->a->name);
	}
}

static void		ft_move_tmp_on_top_b(t_st **stacks, t_elem *cur)
{
	int	rotate;

	rotate = ROTATE;
	if (0 > ft_steps_to_move_current_on_top_b(cur, *stacks))
		rotate = REVERSE;
	while ((*stacks)->b != cur)
	{
		if (rotate > 0)
			ft_ra_rb(stacks, (*stacks)->b->name);
		else
			ft_rra_rrb(stacks, (*stacks)->b->name);
	}
}

void			ft_push_tmp_to_a(t_st **stacks, t_elem *cur)
{
	ft_move_tmp_on_top_b(stacks, cur);
//	ft_print_stack_step(*stacks);//todo del
	ft_ready_stack_a_to_push(stacks, cur);
//	ft_print_stack_step(*stacks);//todo del
	ft_pa_pb(stacks, (*stacks)->b->name);
}