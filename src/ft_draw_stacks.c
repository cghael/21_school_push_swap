/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 16:14:25 by cghael            #+#    #+#             */
/*   Updated: 2020/07/27 16:14:26 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		ft_draw_line(t_vis *vps, t_line *current)
{
	int x;
	int y;
	int i;

	x = current->x_start;
	while (x < current->x_end)
	{
		y = current->y_start;
		while (y < current->y_end)
		{
			i = (x * vps->bits_per_pixel / 8) + (y * vps->size_line);
			vps->data_addr[i] = (char)YELLOW;
			vps->data_addr[++i] = (char)(YELLOW >> 8);
			vps->data_addr[++i] = (char)(YELLOW >> 16);
			y++;
		}
		x++;
	}
}

static t_line	*ft_create_line(int x_start, int x_end, int y_start, int y_end)
{
	t_line	*tmp;

	tmp = ft_memalloc(sizeof(t_line));
	if (!tmp)
		return (NULL);
	tmp->x_start = x_start;
	tmp->x_end = x_end;
	tmp->y_start = y_start;
	tmp->y_end = y_end;
	return (tmp);
}

static void		ft_draw_one_stack(t_ps *push_swap, t_vis *vps, t_elem *stack)
{
	int		i;
	int		size;
	int		x_start;
	t_line	*current_line;

	x_start = 0;
	if (stack->name == 'b')
		x_start = WIDTH / 2;
	size = push_swap->stacks->qnty_a;
	if (stack->name == 'b')
		size = push_swap->stacks->qnty_b;
	i = 0;
	while (i < size)
	{
		if (!(current_line = ft_create_line(x_start, \
						x_start + (stack->index + 1) * push_swap->width, \
						i * push_swap->height, (i + 1) * push_swap->height)))
			ft_error_exit("Error in ft_draw_one_stack()\n", NULL);
		ft_draw_line(vps, current_line);
		free(current_line);
		stack = stack->next;
		i++;
	}
}

void			ft_draw_stacks(t_ps *push_swap, t_vis *vps)
{
	if (push_swap->stacks->a)
		ft_draw_one_stack(push_swap, vps, push_swap->stacks->a);
	if (push_swap->stacks->b)
		ft_draw_one_stack(push_swap, vps, push_swap->stacks->b);
}
