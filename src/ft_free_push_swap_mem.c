//
// Created by Anton on 19.04.2020.
//

#include "push_swap.h"

void		ft_free_push_swap_mem(t_order *cmd_stack, t_elem *stack_a)
{
	ft_free_stack(stack_a);
	ft_free_cmd_stack(cmd_stack);
}