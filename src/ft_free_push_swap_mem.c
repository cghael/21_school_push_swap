//
// Created by Anton on 19.04.2020.
//

#include "push_swap.h"

void		ft_free_push_swap_mem(t_st *stacks)
{
	ft_free_stack(stacks->a);
	ft_free_cmd_stack(stacks->cmd);
	free(stacks);
}