//
// Created by Anton on 19.04.2020.
//

#include "push_swap.h"

void		ft_free_cmd_stack(t_order *cmd_stack)
{
	t_order *tmp;

	tmp = cmd_stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(cmd_stack);
		cmd_stack = tmp;
	}
}