/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_order_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:59:57 by cghael            #+#    #+#             */
/*   Updated: 2020/07/21 12:59:59 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_add_new_to_order(t_order **cmd_stack, t_order *new)
{
	t_order	*tmp;

	tmp = *cmd_stack;
	if (*cmd_stack == NULL)
		*cmd_stack = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static t_order	*ft_write_command(t_order *new, char *str)
{
	int	i;

	i = 0;
	if (str[0] == '_')
		str++;
	while (str[i])
	{
		new->command[i] = str[i];
		i++;
	}
	new->next = NULL;
	return (new);
}

void			ft_new_order_add(t_order **cmd_stack, char *str)
{
	t_order	*new;

	new = malloc(sizeof(t_order));
	if (new == NULL)
	{
		ft_free_cmd_stack(*cmd_stack);
		ft_error_exit("Error malloc in ft_new_order_add\n", NULL);
	}
	ft_bzero(new, sizeof(t_order));
	new = ft_write_command(new, str);
	ft_add_new_to_order(cmd_stack, new);
	(*cmd_stack)->step_numb++;
}
