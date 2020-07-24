/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_t_st_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <cghael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:04:13 by cghael            #+#    #+#             */
/*   Updated: 2020/06/30 10:44:04 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st	*ft_create_t_st_elem(void)
{
	t_st	*new;

	new = malloc(sizeof(t_st));
	if (new == NULL)
		ft_error_exit("Error malloc in ft_create_t_st_elem\n", NULL);
	new->a = NULL;
	new->b = NULL;
	new->cmd = NULL;
	new->qnty_a = 0;
	new->qnty_b = 0;
	return (new);
}
