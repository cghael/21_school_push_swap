/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:32:32 by cghael            #+#    #+#             */
/*   Updated: 2020/07/27 13:32:34 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_vis		*ft_get_vis(void)
{
	t_vis	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_vis))))
		ft_error_exit("Error in ft_get_vis()\n", NULL);
	if (!(tmp->mlx = mlx_init()))
		ft_error_exit("Error in ft_get_vis()\n", NULL);
	if (!(tmp->wndw = mlx_new_window(tmp->mlx, WIDTH, HEIGHT, "Push_swap")))
		ft_error_exit("Error in ft_get_vis()\n", NULL);
	if (!(tmp->img = mlx_new_image(tmp->mlx, WIDTH, HEIGHT)))
		ft_error_exit("Error in ft_get_vis()\n", NULL);
	tmp->data_addr = mlx_get_data_addr(tmp->img, &(tmp->bits_per_pixel), \
											&(tmp->size_line), &(tmp->endian));
	return (tmp);
}
