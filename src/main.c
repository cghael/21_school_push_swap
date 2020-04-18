//
// Created by Anton on 04.04.2020.
//

#include "push_swap.h"

int			main(int argc, char *argv[])
{
	t_elem	*stack_a;
	t_order	*cmd_stack;

	stack_a = ft_check_n_write_args(argc, argv);
	cmd_stack = ft_sort_stack_a(stack_a);
//	ft_print_operations(cmd_stack);
//	ft_free_ps_mem(cmd_stack, stack_a);
	write(1, "OK\n", 3);
	return (0);
}