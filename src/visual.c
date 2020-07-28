/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:32:02 by cghael            #+#    #+#             */
/*   Updated: 2020/07/27 13:32:05 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int			ft_close(void *param)
{
	(void)param;
	exit(0);
}

int				ft_deal_key(int key, t_vis *vps)
{
	int		pressed;
//	int		size;
//	char	*line;
//	t_flags	options;

//	options.visual = FALSE;
	pressed = key;
	if (pressed == 53)
	{
		mlx_destroy_window(vps->mlx, vps->wndw);
//		free(mlx->map.px);
		exit(0);
	}
//	if (pressed == 49)
//	{
//		write(1, "penis\n", 1);
//		while ((size = ft_get_next_line(0, &line)) > 0)
//		{
//			ft_run_cmd(line, &push_swap->stacks, options);
//			free(line);
//			ft_draw(push_swap, vps);
//		}
//		if (size == -1)
//		{
//			ft_free_push_swap_mem(push_swap->stacks);
//			ft_error_exit("Error in ft_get_next_line()\n", NULL);
//		}
//	}
	return (0);
}

static void	ft_visualize(t_ps *push_swap, t_vis *vps)
{
	int		size;
	char	*line;
	t_flags	options;

	options.visual = FALSE;
//	mlx_hook(vps->wndw, 2, 0, ft_deal_key, vps);
	mlx_hook(vps->wndw, 17, 0, ft_close, vps);
	ft_draw(push_swap, vps);
	while ((size = ft_get_next_line(0, &line)) > 0)
	{
//		ft_printf("\n%s\n", line);
		ft_run_cmd(line, &push_swap->stacks, options);
		free(line);
		ft_draw(push_swap, vps);
	}
	if (size == -1)
	{
		ft_free_push_swap_mem(push_swap->stacks);
		ft_error_exit("Error in ft_get_next_line()\n", NULL);
	}
	mlx_loop(vps->mlx);
}

int			main(int argc, char *argv[])
{
	t_vis	*vps;
	t_ps	*push_swap;

	push_swap = ft_get_push_swap(argc, argv);
	vps = ft_get_vis();
	if (push_swap->stacks->qnty_a <= HEIGHT)
		ft_visualize(push_swap, vps);
	else
		ft_error_exit("Too small window height\n", NULL);
	return (0);
}
