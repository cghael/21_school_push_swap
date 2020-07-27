//
// Created by  Anton Gorobets on 25.07.2020.
//

#ifndef VISUAL_H
# define VISUAL_H

# include "push_swap.h"
# include "mlx.h"

# define HEIGHT		1000
# define WIDTH		1000

# define GREY_1		0x333333
# define GREY_2		0x222222
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

t_ps				*ft_get_push_swap(int argc, char *argv[]);
t_vis				*ft_get_vis(void);

#endif //VISUAL_H
