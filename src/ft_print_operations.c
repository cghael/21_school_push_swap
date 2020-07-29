/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:00:59 by cghael            #+#    #+#             */
/*   Updated: 2020/07/21 13:01:00 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_operations(t_order *cmd_stack)
{
	t_order	*tmp;

	tmp = cmd_stack;
	while (tmp != NULL)
	{
		ft_putstr(tmp->command);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
