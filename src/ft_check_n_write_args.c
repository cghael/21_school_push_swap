//
// Created by Anton on 04.04.2020.
//

#include "../includes/push_swap.h"

static void	ft_check_args_number(int argc)
{
	if (argc < 2)
	{
		ft_putstr(USAGE);
		exit (EXIT_CODE);
	}
}

t_elem		*ft_check_n_write_args(int argc, char **argv)
{
	t_elem *stack;

	ft_check_args_number(argc);
	if (argc == 2)
		stack = ft_one_agr(argv);
	else
		stack = ft_multi_arg(argv, argc);
	//TODO проверить, что числа уникальны и индексы проставить
	return (stack);
}
