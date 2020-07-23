/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:25:57 by cghael            #+#    #+#             */
/*   Updated: 2020/07/21 15:25:59 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_flags	ft_check_flags(int argc, char *argv[])
{
	t_flags tmp;

	tmp.color = FALSE;
	tmp.visual = FALSE;
	if (argc >= 2)
	{
		if (ft_strequ(argv[1], "-v"))
		{
			tmp.visual = TRUE;
		}
		else if (ft_strequ(argv[1], "-vc"))
		{
			tmp.visual = TRUE;
			tmp.color = TRUE;
		}
	}
	return (tmp);
}

static void	ft_checker(t_st **stacks, t_flags options, int argc, char *argv[])
{
	int		size;
	char	*line;

	ft_putstr("2\n");
	if (options.visual || options.color)
		ft_print_stack_step(*stacks);
	ft_putstr("4\n");
	while ((size = ft_get_next_line(0, &line)) > 0)
	{
		ft_run_cmd(line, stacks, options);
		free(line);
	}
	ft_putstr("3\n");
	if (size == -1)
	{
		ft_free_push_swap_mem(*stacks);
		ft_error_exit("Error in ft_get_next_line()\n", NULL);
	}
	if ((*stacks)->b == NULL && \
						ft_check_stack_sorted((*stacks)->a, (*stacks)->qnty_a))
//		ft_printf("\n \e[1;32m<<< OK :) >>>\e[m \n");
		ft_putstr("\n \e[1;32m<<< OK :) >>>\e[m \n");
	else
//		ft_printf("\n \e[1;31m<<< KO :'( >>>\e[m \n");
		ft_putstr("\n \e[1;31m<<< KO :'( >>>\e[m \n");
}

int			main(int argc, char *argv[])
{
	t_st	*stacks;
	t_flags	options;

	options = ft_check_flags(argc, argv);
	if (options.visual || options.color)
	{
		argc--;
		argv++;
	}
	stacks = ft_check_n_write_args(argc, argv);
	ft_checker(&stacks, options, argc, argv);
	return (0);
}
