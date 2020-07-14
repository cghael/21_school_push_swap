/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_min_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:10:41 by cghael            #+#    #+#             */
/*   Updated: 2020/07/13 14:43:28 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		*ft_choose_min_str(t_steps *tmp)
{
	int			min;
	int			min_str;
	int			i;
	int			count;

	min_str = 0;
	i = 0;
	min = INT_MAX;
	while (i < 8)
	{
		count = ft_word_count(tmp->var[i], '\n');
		if (min > count && count > 0)
		{
			min_str = i;
			min = count;
		}
		i++;
	}
	return (tmp->var[min_str]);
}

void			ft_run_min_steps(t_steps *tmp, t_st **stacks)
{
	char	*cmd_str;
	char	*cmd_ptr;
	char	*cmd;

	cmd_str = ft_choose_min_str(tmp);

	if (cmd_str)
	{
		while (*cmd_str)
		{
			cmd_ptr = ft_strchr(cmd_str, '\n');
			cmd = ft_strnew(cmd_ptr - cmd_str);
			cmd = ft_strncpy(cmd,cmd_str, cmd_ptr - cmd_str);
			ft_run_cmd(cmd, stacks);
			free(cmd);
			cmd_str = cmd_ptr + 1;
		}
	}
	ft_print_operations((*stacks)->cmd); //todo del
}
