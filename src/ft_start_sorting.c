//
// Created by Anton on 26.06.2020.
//

#include "push_swap.h"

//static int			ft_rotate_steps(t_elem *stack, t_elem **best, int piece)
//{
//	t_elem	*tmp;
//	int		rotate;
//
//	rotate = 1;
//	tmp = stack->next;
//	while (tmp != stack)
//	{
//		if (tmp->index < piece && tmp->stay == 0)
//		{
//			*best = tmp;
//			return (rotate);
//		}
//		tmp = tmp->next;
//		rotate++;
//	}
//	return (-1);
//}

static int		ft_is_any_elem_to_push(t_elem *stack, int piece)
{
//	int		counter;
	t_elem	*tmp;

	tmp = stack->next;
//	counter = 0;
	if (stack->index < piece && stack->stay == 0)
		return (1);
	while (tmp != stack)
	{
		if (tmp->index < piece && tmp->stay == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
//	int		rotate;
//	int		reverse;
//	t_elem	*tmp;
//	t_elem	*best;
//
//	reverse = 1;
//	if (stack->index < piece && stack->stay == 0)
//		return (stack);
//	rotate = ft_rotate_steps(stack, &best, piece);
//	if (rotate < 0)
//		return (NULL);
//	tmp = stack->back;
//	while (tmp != stack)
//	{
//		if (tmp->index < piece && tmp->stay == 0)
//			break ;
//		tmp = tmp->back;
//		reverse++;
//	}
//	if (reverse < rotate)
//		best = tmp;
//	return (best);
}

void			ft_start_sorting(t_st **stacks)
{
	int		piece;
	int		piece_step;
//	t_elem	*tmp;

//	ft_find_presort_pieces(stacks); //todo stack->stay = 1
//	piece_step = ft_find_piece((*stacks)->qnty_a); //todo
	piece_step = 5;
	piece = piece_step;
	while ((*stacks)->a)
	{
//		tmp = ft_is_any_elem_to_push((*stacks)->a, piece);
		while (ft_is_any_elem_to_push((*stacks)->a, piece))
		{
			ft_move_elem_to_b(stacks, piece);
			ft_print_stack_step(*stacks); //todo del
//			tmp = ft_is_any_elem_to_push((*stacks)->a, piece);
		}
		piece += piece_step;
	}
}