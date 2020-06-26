/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_write_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:22:30 by cghael            #+#    #+#             */
/*   Updated: 2020/06/25 13:22:37 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_elem	*ft_elem_index(t_elem *stack)
{
	t_elem	*tmp;
	t_elem	*check_elem;
	int		elem_num;

	tmp = stack;
	while (tmp != stack->back)
	{
		tmp->index = stack->back->index;
		tmp = tmp->next;
	}
	elem_num = tmp->index + 1;
	while (elem_num)
	{
		check_elem = tmp->back;
		while (check_elem != tmp)
		{
			if (check_elem->value < tmp->value)
				check_elem->index--;
			check_elem = check_elem->back;
		}
		tmp = tmp->back;
		elem_num--;
	}
	return (stack);
}

static void		ft_check_args_uniq(t_elem *stack)
{
	int		tmp;
	t_elem	*checked_elem;
	t_elem	*tmp_elem;

	tmp_elem = stack->next;
	tmp = stack->value;
	while (tmp_elem != stack)
	{
		checked_elem = tmp_elem;
		while (checked_elem->value != tmp)
			checked_elem = checked_elem->next;
		if (checked_elem->next != tmp_elem)
		{
			ft_free_stack(stack);
			ft_error_exit(ERR_UNIQ_ARGS, NULL);
		}
		tmp = tmp_elem->value;
		tmp_elem = tmp_elem->next;
	}
}

static void		ft_check_args_number(int argc)
{
	if (argc < 2)
	{
		ft_putstr(USAGE_PUSH_SWAP);
		exit (ERROR_EXIT_CODE);
	}
}

t_st			*ft_check_n_write_args(int argc, char **argv)
{
	t_st	*stacks;

	stacks = ft_create_t_st_elem();
	ft_check_args_number(argc);
	if (argc == 2)
		stacks->a = ft_one_agr(argv);
	else
		stacks->a = ft_multi_arg(argv, argc);
	stacks->qnty_a = stacks->a->back->index + 1;
	if (stacks->qnty_a > 1)
	{
		ft_check_args_uniq(stacks->a);
		stacks->a = ft_elem_index(stacks->a);
	}
	return (stacks);
}
