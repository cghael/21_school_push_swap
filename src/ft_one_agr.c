//
// Created by Anton on 15.04.2020.
//

#include "push_swap.h"

static int		ft_get_int(char **str)
{
	int	numb;
	int	tmp;

	numb = ft_atoi(*str);
	tmp = numb;
	if (tmp < 0)
		(*str)++;
	if (tmp == 0)
		(*str)++;
	else
	{
		while (tmp)
		{
			(*str)++;
			tmp = tmp / 10;
		}
	}
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
		if ((str[i] == '-' && (str[i + 1] < 48 || str[i + 1] > 57))\
			|| (i > 0 && str[i] == '-' && str[i - 1] != ' ')\
			|| (str[i] != ' ' && str[i] != '-' && (str[i] < 48 || str[i] > 57)))
			ft_error_exit(ERR_ARGS, NULL);
		i++;
	}
}

t_elem			*ft_one_agr(char **argv)
{
	t_elem *stack;

	ft_check_str(argv[1]);
	stack = ft_write_args(argv[1]);
	return (stack);
}
