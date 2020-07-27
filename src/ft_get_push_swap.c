//
// Created by  Anton Gorobets on 25.07.2020.
//

#include "visual.h"

t_ps		*ft_get_push_swap(int argc, char *argv[])
{
	t_ps	*tmp;

	tmp = ft_memalloc(sizeof(t_ps));
	if (!tmp)
		ft_error_exit("Error in ft_get_push_swap()\n", NULL);
	tmp->stacks = ft_check_n_write_args(argc, argv);
	tmp->width = WIDTH / 2 / tmp->stacks->qnty_a;
	tmp->height = HEIGHT / tmp->stacks->qnty_a;
	return (tmp);
}
