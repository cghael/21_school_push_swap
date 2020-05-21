//
// Created by Anton on 21.05.2020.
//

#include "push_swap.h"

int		ft_find_pivot(t_elem *src, int move)
{
	int pivot;
	int counter;

	counter = move;
	pivot = 0;
	while (counter)
	{
		pivot += src->index;
		src = src->next;
		counter--;
	}
	pivot = pivot / move;
	if (move % 2 == 0)
		pivot++;
	return (pivot);
}