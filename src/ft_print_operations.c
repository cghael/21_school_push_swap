//
// Created by Anton on 19.04.2020.
//

#include "push_swap.h"

void		ft_print_operations(t_order *cmd_stack)
{
	t_order	*tmp;

	tmp = cmd_stack;
	while (tmp != NULL)
	{
		ft_putstr(tmp->command);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}