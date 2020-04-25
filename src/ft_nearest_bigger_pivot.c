//
// Created by Anton on 25.04.2020.
//

#include "push_swap.h"

static int	ft_check_for_elem_exist(t_elem *stack, int pivot)
{
	t_elem	*tmp;
	int		n;

	n = stack->qnty;
	tmp = stack;
	while (n)
	{
		if (tmp->index > pivot)
			return (EXIST);
		tmp = tmp->next;
		n--;
	}
	return (NOT_EXIST);
}

int			ft_nearest_bigger_pivot(t_elem *stack, int pivot)
{
	int		rotate_steps;
	int		reverse_steps;
	t_elem	*step_elem;

	rotate_steps = 0;
	reverse_steps = 0;
	step_elem = stack;
	if (NOT_EXIST == ft_check_for_elem_exist(stack, pivot))
		return (NOT_EXIST);
	while (step_elem->index <= pivot)
	{
		step_elem = step_elem->next;
		rotate_steps++;
	}
	step_elem = stack;
	while (step_elem->index <= pivot)
	{
		step_elem = step_elem->back;
		reverse_steps++;
	}
	if (rotate_steps < reverse_steps)
	{
		ft_putstr("Choose rotate\n"); //TODO del
		return (ROTATE);
	}
	ft_putstr("Choose reverse\n");//TODO del
	return(REVERSE_ROTATE);
}