/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 16:14:39 by cghael            #+#    #+#             */
/*   Updated: 2020/07/27 16:14:42 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "push_swap.h"
# include "mlx.h"

# define HEIGHT		1000
# define WIDTH		1000

# define GREY		0x333333
# define YELLOW		0xF0D347

typedef struct		s_vis
{
	void			*mlx;
	void			*wndw;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_vis;

typedef struct		s_ps
{
	int				width;
	int				height;
	t_st			*stacks;
}					t_ps;

typedef struct		s_line
{
	int				x_start;
	int				x_end;
	int				y_start;
	int				y_end;
}					t_line;

t_ps				*ft_get_push_swap(int argc, char *argv[]);
t_vis				*ft_get_vis(void);
void				ft_draw(t_ps *push_swap, t_vis *vps);
void				ft_draw_stacks(t_ps *push_swap, t_vis *vps);

#endif //VISUAL_H
