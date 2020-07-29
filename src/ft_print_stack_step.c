/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack_step.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:24:45 by cghael            #+#    #+#             */
/*   Updated: 2020/06/25 13:24:52 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_line(int counter, t_elem **tmp, char ch, int c_flag)
{
	if (counter > 0)
	{
		if (ch == 'a' && c_flag)
			ft_printf("\e[1;34m%11d\e[m", (*tmp)->value);
		else if (ch == 'a')
			ft_printf("%11d", (*tmp)->value);
		else if (ch == 'b' && c_flag)
			ft_printf("|\e[1;34m%11d\e[m\n", (*tmp)->value);
		else
			ft_printf("|%11d\n", (*tmp)->value);
		*tmp = (*tmp)->next;
	}
	else
	{
		if (ch == 'a')
			ft_printf("           ");
		else
			ft_printf("|           \n");
	}
}

static int	ft_line_flag(int c_cnt, char *cmd, char name, int qnty)
{
	if (name == 'a' && cmd)
	{
		if ((c_cnt == 0 && (ft_strequ(cmd, "ra") || ft_strequ(cmd, "rr") || \
			ft_strequ(cmd, "pa"))) || (c_cnt < 2 && ft_strequ(cmd, "sa")) || \
			(c_cnt == qnty - 1 && (ft_strequ(cmd, "rra") || \
			ft_strequ(cmd, "rrr"))))
			return (1);
		else
			return (0);
	}
	else if (cmd)
	{
		if ((c_cnt == 0 && (ft_strequ(cmd, "rb") || ft_strequ(cmd, "rr") || \
			ft_strequ(cmd, "pb"))) || (c_cnt < 2 && ft_strequ(cmd, "sb")) || \
			(c_cnt == qnty - 1 && (ft_strequ(cmd, "rrr") || \
			ft_strequ(cmd, "rrb"))))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

void		ft_print_stack_step(t_st *stacks, char *cmd, int color)
{
	int		counter_a;
	int		counter_b;
	int		c_counter;
	int		c_flag;

	c_flag = 0;
	c_counter = 0;
	counter_a = (stacks->a) ? stacks->qnty_a : 0;
	counter_b = (stacks->b) ? stacks->qnty_b : 0;
	ft_printf("  STACK A  |  STACK B  \n-----------|-----------\n");
	while (counter_a > 0 || counter_b > 0)
	{
		if (stacks->a && color)
			c_flag = ft_line_flag(c_counter, cmd, 'a', stacks->qnty_a);
		ft_print_line(counter_a, &stacks->a, 'a', c_flag);
		c_flag = 0;
		if (stacks->b && color)
			c_flag = ft_line_flag(c_counter, cmd, 'b', stacks->qnty_b);
		ft_print_line(counter_b, &stacks->b, 'b', c_flag);
		counter_a--;
		counter_b--;
		c_counter++;
	}
	ft_printf("-----------------------\n\n");
}
