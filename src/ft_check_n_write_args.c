//
// Created by Anton on 04.04.2020.
//

#include "../includes/push_swap.h"

static void		ft_check_args_uniq(t_elem *stack)
{
	int		tmp;
	t_elem	*checked_elem;
	t_elem	*tmp_elem;

	tmp_elem = stack->next;
	tmp = stack->value;
	while (tmp_elem != stack)
	{
		checked_elem = tmp_elem;
		while (checked_elem->value != tmp)
			checked_elem = checked_elem->next;
		if (checked_elem->next != tmp_elem)
		{
			ft_free_stack(stack);
			ft_error_exit(ERR_UNIQ_ARGS, NULL);
		}
		tmp = tmp_elem->value;
		tmp_elem = tmp_elem->next;
	}
}

static void		ft_check_args_number(int argc)
{
	if (argc < 2)
	{
		ft_putstr(USAGE);
		exit (EXIT_CODE);
	}
}

t_elem			*ft_check_n_write_args(int argc, char **argv)
{
	t_elem *stack;

	ft_check_args_number(argc);
	if (argc == 2)
		stack = ft_one_agr(argv);
	else
		stack = ft_multi_arg(argv, argc);
	//TODO проверить, что числа уникальны и индексы проставить
	ft_check_args_uniq(stack);
	//stack = ft_elem_index(stack);
	return (stack);
}
