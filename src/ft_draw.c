/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:33:11 by cghael            #+#    #+#             */
/*   Updated: 2020/07/27 13:33:13 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		ft_draw_backgraund(t_vis *vps)
{
	int *img;
	int i;

	ft_bzero(vps->data_addr, WIDTH * HEIGHT * (vps->bits_per_pixel / 8));
	i = 0;
	img = (int*)(vps->data_addr);
	while (i < HEIGHT * WIDTH)
	{
		img[i] = GREY;
		i++;
	}
}

void			ft_draw(t_ps *push_swap, t_vis *vps)
{
	ft_draw_backgraund(vps);
	ft_draw_stacks(push_swap, vps);
	mlx_put_image_to_window(vps->mlx, vps->wndw, vps->img, 0, 0);
	mlx_do_sync(vps->mlx);
}
