//
// Created by Anton on 21.05.2020.
//

#include "push_swap.h"

int			ft_side_to_rotate(int pivot, t_elem **src)
{
	int		rotate;
	int		reverse;
	t_elem	*tmp;

	tmp = *src;
	rotate = 0;
	reverse = 0;
	while ((tmp->name == 'a' && tmp->index >= pivot) \
			|| (tmp->name == 'b' && tmp->index < pivot))
	{
		rotate++;
		tmp = tmp->next;
	}
	tmp = *src;
	while ((tmp->name == 'a' && tmp->index > pivot) \
			|| (tmp->name == 'b' && tmp->index < pivot))
	{
		reverse++;
		tmp = tmp->back;
	}
	if (rotate <= reverse)
		return (ROTATE);
	return (REVERSE);
}