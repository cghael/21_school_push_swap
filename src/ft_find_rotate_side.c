//
// Created by Anton on 25.04.2020.
//

#include "push_swap.h"

int			ft_find_rotate_side(t_elem *stack, int tmp_index)
{
	int		rotate_steps;
	int		reverse_steps;
	t_elem	*step_elem;

	rotate_steps = 0;
	reverse_steps = 0;
	step_elem = stack;
	while (step_elem->index != tmp_index)
	{
		step_elem = step_elem->next;
		rotate_steps++;
	}
	step_elem = stack;
	while (step_elem->index != tmp_index)
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