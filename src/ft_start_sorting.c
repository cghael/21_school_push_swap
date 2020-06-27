//
// Created by Anton on 26.06.2020.
//

#include "push_swap.h"

static void		ft_find_presort_pieces(t_st **stacks)
{
	t_elem	*tmp;

	//always stay biggest elem
	tmp = (*stacks)->a->next;
	if ((*stacks)->a->index == (*stacks)->qnty_a - 1)
		(*stacks)->a->stay = 1;
	while (tmp != (*stacks)->a)
	{
		if (tmp->index == (*stacks)->qnty_a - 1)
		{
			tmp->stay = 1;
			break ;
		}
		tmp = tmp->next;
	}

	//stay three biggest elem
	tmp = (*stacks)->a->next;
	while (tmp != (*stacks)->a)
	{
		if (tmp->index >= (*stacks)->qnty_a - 3)
			tmp->stay = 1;
		tmp = tmp->next;
	}
	if (tmp->index >= (*stacks)->qnty_a - 3)
		tmp->stay = 1;
}

static void		ft_move_elem_to_b(t_st **stacks, int piece)
{
	if (ROTATE == ft_find_rotate_side((*stacks)->a, piece))
	{
		while ((*stacks)->a->index >= piece || (*stacks)->a->stay == 1)
			ft_ra_rb(stacks, (*stacks)->a->name);
	}
	else
	{
		while ((*stacks)->a->index >= piece || (*stacks)->a->stay == 1)
			ft_rra_rrb(stacks, (*stacks)->a->name);
	}
	ft_pa_pb(stacks, (*stacks)->a->name);
}

static int		ft_is_any_elem_to_push(t_elem *stack, int piece)
{
	int		counter;
	t_elem	*tmp;

	tmp = stack->next;
	counter = 0;
	if (stack->index < piece && stack->stay == 0)
		counter++;
	while (tmp != stack)
	{
		if (tmp->index < piece && tmp->stay == 0)
			counter++;
		tmp = tmp->next;
	}
	return (counter);
}

void			ft_start_sorting(t_st **stacks)
{
	int	piece;
	int	piece_step;
	int	qnty;

	qnty = (*stacks)->qnty_a; //because qnty_a is changed
	ft_find_presort_pieces(stacks); //todo stack->stay = 1
//	piece_step = ft_find_piece((*stacks)->qnty_a); //todo
	piece_step = 100;
	piece = piece_step;
	while (piece <= qnty)
	{
		while (ft_is_any_elem_to_push((*stacks)->a, piece))
		{
			ft_move_elem_to_b(stacks, piece);
			ft_print_stack_step(*stacks); //todo del
		}
		piece += piece_step;
	}
}