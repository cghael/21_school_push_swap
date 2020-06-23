//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

static void	ft_print_line(int counter, t_elem *tmp, char ch)
{
	if (counter > 0)
	{
		if (ch == 'a')
			ft_printf("%7d", tmp->index);
		else
			ft_printf("|%7d\n", tmp->index);
	}
	else
	{
		if (ch == 'a')
			ft_printf("       ");
		else
			ft_printf("|       \n");
	}
}

void		ft_print_stack_step(t_st *stacks)
{
	int		counter_a;
	int		counter_b;

	counter_a = (stacks->a) ? stacks->a->qnty : 0;
	counter_b = (stacks->b) ? stacks->b->qnty : 0;
	ft_printf("STACK A|STACK B\n-------|-------\n");
	while (counter_a > 0 || counter_b > 0)
	{
		ft_print_line(counter_a, stacks->a, 'a');
		ft_print_line(counter_b, stacks->b, 'b');
		stacks->a = stacks->a->next;
		stacks->b = stacks->b->next;
		counter_a--;
		counter_b--;
	}
	ft_printf("---------------\n\n");
}