//
// Created by  Anton Gorobets on 25.07.2020.
//

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
