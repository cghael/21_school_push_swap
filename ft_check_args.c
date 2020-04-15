//
// Created by Anton on 04.04.2020.
//

#include "push_swap.h"

static void	ft_check_args_number(int argc)
{
	if (argc != 2)
	{
		ft_putstr(USAGE);
		exit (EXIT_CODE);
	}
}

void		ft_check_args(int argc, char *argv[])
{
	ft_check_args_number(argc);
}
