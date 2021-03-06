/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:57:34 by cghael            #+#    #+#             */
/*   Updated: 2020/07/14 12:57:37 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_visual_print(char *cmd, t_st **stacks, t_flags options)
{
	if (options.visual)
	{
		ft_printf("%s\n", cmd);
		ft_print_stack_step(*stacks, cmd, options.color);
	}
}

void			ft_run_cmd(char *cmd, t_st **stacks, t_flags options)
{
	if (ft_strequ(cmd, "ra"))
		ft_ra_rb(stacks, 'a');
	else if (ft_strequ(cmd, "rb"))
		ft_ra_rb(stacks, 'b');
	else if (ft_strequ(cmd, "rra"))
		ft_rra_rrb(stacks, 'a');
	else if (ft_strequ(cmd, "rrb"))
		ft_rra_rrb(stacks, 'b');
	else if (ft_strequ(cmd, "rr"))
		ft_rr_rrr(stacks, ROTATE);
	else if (ft_strequ(cmd, "rrr"))
		ft_rr_rrr(stacks, REVERSE);
	else if (ft_strequ(cmd, "pa"))
		ft_pa_pb(stacks, 'b');
	else if (ft_strequ(cmd, "pb"))
		ft_pa_pb(stacks, 'a');
	else if (ft_strequ(cmd, "sa"))
		ft_sa_sb(stacks, 'a');
	else if (ft_strequ(cmd, "sb"))
		ft_sa_sb(stacks, 'b');
	else if (ft_strequ(cmd, "ss"))
		ft_sa_sb(stacks, 'x');
	else
		ft_error_exit("Error\n", NULL);
	ft_visual_print(cmd, stacks, options);
}
