//
// Created by Anton Gorobets on 16.04.20.
//

#include "push_swap.h"

static void	ft_add_new_to_stack(t_elem **stack, t_elem *new)
{
	t_elem *tmp;
	int		counter;

	tmp = *stack;
	counter = 1;
	if (tmp == NULL)
	{
		*stack = new;
		(*stack)->back = *stack;
		(*stack)->next = *stack;
	}
	else
	{
		while (tmp->next != *stack)
		{
			counter++;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->back = tmp;
		new->next = *stack;
		(*stack)->back = new;
		new->index = counter;
	}
}

void		ft_new_elem_add(t_elem **stack, int numb)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (new == NULL)
	{
		ft_free_stack(*stack);
		ft_error_exit("Error malloc in ft_new_elem_add\n", new);
	}
	new->value = numb;
	new->next = NULL;
	new->back = NULL;
	new->index = 0;
	new->qnty = 0;
	ft_add_new_to_stack(stack, new);
}