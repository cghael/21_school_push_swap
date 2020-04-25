//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

void		ft_move_a_and_adjust_b(t_order **cmd_stack, t_elem **stack_a, \
										t_elem **stack_b, t_elem *tmp)
{
	//move tmp elem at the top of stack_a
	while(*stack_a != tmp)
	{
		if (ROTATE == ft_find_rotate_side(*stack_a, tmp->index))
			ft_ra_rb(cmd_stack, stack_a, 'a');
		else
			ft_rra_rrb(cmd_stack, stack_a, 'a');
		ft_print_stack_step(*stack_a, *stack_b); //TODO del
	}

	//move stack_b to put tmp in a sorted way
	if (*stack_b)
	{
		//find the elem in stack_b to adjust
		tmp = ft_adjust_big_to_small_stack(cmd_stack, stack_b, tmp->index);
		if (tmp)
		{
			while (*stack_b != tmp)
			{
				if (ROTATE == ft_find_rotate_side(*stack_b, tmp->index))
					ft_ra_rb(cmd_stack, stack_b, 'b');
				else
					ft_rra_rrb(cmd_stack, stack_b, 'b');
				ft_print_stack_step(*stack_a, *stack_b); //TODO del
			}
		}
	}
	ft_pa_pb(cmd_stack, stack_a, stack_b, 'b');
	ft_print_stack_step(*stack_a, *stack_b); //TODO del
}

void		ft_push_to_b_after_pivot(t_order **cmd_stack, t_elem **stack_a, \
										t_elem **stack_b)
{
	int		pivot;

	int		n;
	t_elem	*tmp;

	pivot = ((*stack_a)->qnty / 2 + (*stack_a)->qnty % 2) - 1;
	n = (*stack_a)->qnty;
	tmp = *stack_a;


//	if (ROTATE == ft_nearest_bigger_pivot(*stack_a, pivot)) //TODO while (EXIST)


	while (n) //TODO choose which side searching >pivot
	{
		if (tmp->index > pivot)
		{
			ft_move_a_and_adjust_b(cmd_stack, stack_a, stack_b, tmp);
			tmp = *stack_a;
		}
		else
			tmp = tmp->next;
		n--;
	}
}