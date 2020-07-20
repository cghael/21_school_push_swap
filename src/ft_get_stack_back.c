/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:54:41 by cghael            #+#    #+#             */
/*   Updated: 2020/07/14 14:54:47 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void		ft_move_first_elem_on_top_a(t_st **stacks)
//{
//	int		n;
//	t_elem	*tmp;
//
//	n = (*stacks)->qnty_a;
//	tmp = (*stacks)->a;
//	while (n)
//	{
//		if (tmp->index == 0)
//			break ;
//		tmp = tmp->next;
//		n--;
//	}
//	if (n < (*stacks)->qnty_a - n)
//	{
//		while ((*stacks)->a->index != 0)
//		{
//			ft_rra_rrb(stacks, (*stacks)->a->name);
//			ft_print_stack_step(*stacks);//todo del
//		}
//	}
//	else
//	{
//		while ((*stacks)->a->index != 0)
//		{
//			ft_ra_rb(stacks, (*stacks)->a->name);
//			ft_print_stack_step(*stacks);//todo del
//		}
//	}
//}

static void		ft_move_stack_a_min_elem_top(t_st **stacks)
{
	int		n;
	t_elem	*tmp;

	n = (*stacks)->qnty_a;
	tmp = (*stacks)->a;
	while (n)
	{
		if (tmp->index == 0)
			break ;
		tmp = tmp->next;
		n--;
	}
	if (n < (*stacks)->qnty_a - n)
	{
		while ((*stacks)->a->index != 0)
		{
			ft_rra_rrb(stacks, (*stacks)->a->name);
			ft_print_stack_step(*stacks);//todo del
		}
	}
	else
	{
		while ((*stacks)->a->index != 0)
		{
			ft_ra_rb(stacks, (*stacks)->a->name);
			ft_print_stack_step(*stacks);//todo del
		}
	}
}

//static void		ft_move_first_elems_on_stacks_top(t_st **stacks)
//{
//
//}
//
//static void		ft_move_first_elem_on_top_b(t_st **stacks)
//{
//	int		rotate;
//	t_elem	*tmp;
//
//	rotate = 0;
//	tmp = (*stacks)->b;
//	while (tmp->index < tmp->back->index || tmp->index < tmp->next->index)
//	{
//		tmp = tmp->next;
//		rotate++;
//	}
//	if (rotate > (*stacks)->qnty_b - rotate)
//		rotate = rotate - (*stacks)->qnty_b;
//	while ((*stacks)->b->index < (*stacks)->b->back->index ||
//			(*stacks)->b->index < (*stacks)->b->next->index)
//	{
//		if (rotate > 0)
//			ft_ra_rb(stacks, (*stacks)->b->name);
//		else
//			ft_rra_rrb(stacks, (*stacks)->b->name);
//	}
//}

static void		ft_run_min_steps(t_steps *tmp, t_st **stacks)
{
	char	*cmd_str;
	char	*cmd_ptr;
	char	*cmd;

	cmd_str = tmp->var[tmp->min_var];

	if (cmd_str)
	{
		while (*cmd_str)
		{
			cmd_ptr = ft_strchr(cmd_str, '\n');
			cmd = ft_strnew(cmd_ptr - cmd_str);
			cmd = ft_strncpy(cmd,cmd_str, cmd_ptr - cmd_str);
			ft_run_cmd(cmd, stacks);
			free(cmd);
			cmd_str = cmd_ptr + 1;
		}
	}
//	ft_print_operations((*stacks)->cmd); //todo del
}

void			ft_get_stack_back(t_st **stacks)
{
	t_steps	*tmp;

	while ((*stacks)->b)
	{
		tmp = ft_choose_optimal_step(stacks);
		ft_run_min_steps(tmp, stacks);
//		ft_print_stack_step(*stacks); //todo del
	}
	ft_move_stack_a_min_elem_top(stacks);
//	tmp = ft_choose_optimal_step(stacks);
//	ft_run_min_steps(tmp, stacks);
//	ft_print_stack_step(*stacks); //todo del


//	while ((*stacks)->b)
//	{
//		if ((*stacks)->b->index > (*stacks)->a->index && \
//			(*stacks)->b->index < (*stacks)->a->back->index)
//		{
//			ft_print_stack_step(*stacks);
//			ft_move_stack_a_min_elem_top(stacks);
//		}
//		ft_pa_pb(stacks, (*stacks)->b->name);
//	}
//	ft_move_first_elem_on_top_a(stacks);
//		ft_pa_pb(stacks, (*stacks)->b->name);
}
