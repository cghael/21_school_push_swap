/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_agr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:00:23 by cghael            #+#    #+#             */
/*   Updated: 2020/07/21 13:00:25 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_get_int(char **str)
{
	int	numb;

	if (ft_max_min_int(*str) < 0)
		ft_error_exit("Error\n", NULL);
	numb = ft_atoi(*str);
	while (**str != ' ' && **str != '\0')
		(*str)++;
	return (numb);
}

static t_elem	*ft_write_args(char *str)
{
	t_elem	*stack;
	int		numb;

	stack = NULL;
	while (*str)
	{
		if (*str != ' ')
		{
			numb = ft_get_int(&str);
			ft_new_elem_add(&stack, numb);
		}
		else
			str++;
	}
	return (stack);
}

static void		ft_check_str(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (((str[i] == '-' || str[i] == '+') && NOT_A_NUMB(str[i + 1])) || \
			(i > 0 && ((str[i] == '-' || str[i] == '+') && str[i - 1] != ' ')) \
			|| (str[i] != ' ' && str[i] != '-' && str[i] != '+' && \
			NOT_A_NUMB(str[i])) || (str[i] == ' ' && str[i + 1] == ' ') || \
			str[ft_strlen(str) - 1] == ' ' || (NOT_A_NUMB(str[0]) && \
			str[0] != '-' && str[0] != '+'))
			ft_error_exit(ERR_ARGS, NULL);
		i++;
	}
}

t_elem			*ft_one_agr(char **argv)
{
	t_elem *stack;

	ft_check_str(argv[1]);
	stack = ft_write_args(argv[1]);
	if (!stack)
		ft_error_exit(ERR_ARGS, NULL);
	return (stack);
}
