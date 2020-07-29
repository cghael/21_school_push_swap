/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:59:24 by cghael            #+#    #+#             */
/*   Updated: 2020/07/21 12:59:26 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem	*ft_write_multi_args(char **argv, int argc)
{
	t_elem	*stack;
	int		numb;
	int		j;

	j = 1;
	stack = NULL;
	while (j < argc)
	{
		numb = ft_atoi(argv[j]);
		ft_new_elem_add(&stack, numb);
		j++;
	}
	return (stack);
}

static void		ft_check_args(char **argv, int argc)
{
	int		i;
	int		j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if ((argv[j][i] == '-' && NOT_A_NUMB(argv[j][i + 1])) || \
				(argv[j][i] != '-' && NOT_A_NUMB(argv[j][i])))
				ft_error_exit(ERR_ARGS, NULL);
			i++;
		}
		j++;
	}
}

t_elem			*ft_multi_arg(char **argv, int argc)
{
	t_elem *stack;

	ft_check_args(argv, argc);
	stack = ft_write_multi_args(argv, argc);
	return (stack);
}
