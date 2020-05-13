//
// Created by Anton on 25.04.2020.
//

#include "push_swap.h"

t_elem					*ft_adjust_big_to_small_stack(t_order **cmd_stack, \
										t_elem **stack, int index)
{
	t_elem	*tmp;
	int		n;
	
	tmp = *stack; //we think, that stack is sorted from biggest to smallest
	n = (*stack)->qnty;
	if (n < 2)
		return (NULL);
	while (n)
	{
		if ((tmp->index < index && tmp->back->index > index) \
			|| (tmp->index < index && tmp->back->index < index \
			&& tmp->back->index < tmp->index) || (tmp->index > index \
			&& tmp->back->index > index && tmp->index > tmp->back->index))
			break ;
		tmp = tmp->next;
		n--;
	}
	if (*stack != tmp)
		return (tmp);
	return (NULL);
}