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

static void	ft_checker(t_st *stacks, int visual)
{

}

int			main(int argc, char *argv[])
{
	t_st	*stacks;
	int		visual;

	visual = FALSE;
	if (argc >= 2 && ft_strequ(argv[1], "-v"))
	{
		argc--;
		argv++;
		visual = TRUE;
	}
	stacks = ft_check_n_write_args(argc, argv);
	ft_checker(stacks, visual);
	return (0);
}
