/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:55:26 by cghael            #+#    #+#             */
/*   Updated: 2020/07/21 12:55:28 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_cmd_stack(t_order *cmd_stack)
{
	t_order *tmp;

	tmp = cmd_stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(cmd_stack);
		cmd_stack = tmp;
	}
}
