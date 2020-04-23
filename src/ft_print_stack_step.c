//
// Created by Anton on 23.04.2020.
//

#include "push_swap.h"

static void	ft_print_line(int counter, t_elem **tmp, char ch)
{
	if (counter > 0)
	{
		if (ch == 'a')
			ft_printf("%7d", (*tmp)->index);
		else
			ft_printf("|%7d\n", (*tmp)->index);
		*tmp = (*tmp)->next;
	}
	else
	{
		if (ch == 'a')
			ft_printf("       ");
		else
			ft_printf("|       \n");
	}
}

void		ft_print_stack_step(t_elem *stack_a, t_elem *stack_b)
{
	t_elem	*tmp_a;
	t_elem	*tmp_b;
	int		counter_a;
	int		counter_b;

	counter_a = (stack_a) ? stack_a->qnty : 0;
	counter_b = (stack_b) ? stack_b->qnty : 0;
	tmp_a = stack_a;
	tmp_b = stack_b;
	ft_printf("STACK A|STACK B\n-------|-------\n");
	while (counter_a > 0 || counter_b > 0)
	{
		ft_print_line(counter_a, &tmp_a, 'a');
		ft_print_line(counter_b, &tmp_b, 'b');
		counter_a--;
		counter_b--;
	}
	ft_printf("---------------\n\n");
}