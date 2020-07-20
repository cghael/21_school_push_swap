//
// Created by  Anton Gorobets on 20.07.2020.
//

#include "push_swap.h"

static char	*ft_create_rra_rb_cmd(t_steps *tmp, t_st **stacks)
{
	char	*cmd;
	return (cmd);
}

static char	*ft_create_rra_rrb_cmd(t_steps *tmp, t_st **stacks)
{
	char	*cmd;
	return (cmd);
}

static char	*ft_create_ra_rrb_cmd(t_steps *tmp, t_st **stacks)
{
	char	*cmd;
	return (cmd);
}

static char	*ft_create_ra_rb_cmd(t_steps *tmp, t_st **stacks)
{
	char	*cmd;
	return (cmd);
}

char		*ft_create_cmd(t_steps *tmp, t_st **stacks)
{
	char *cmd;

	if (tmp->min_var == 0)
		cmd = ft_create_ra_rb_cmd(tmp, stacks);
	else if (tmp->min_var == 1)
		cmd = ft_create_ra_rrb_cmd(tmp, stacks);
	else if (tmp->min_var == 2)
		cmd = ft_create_rra_rrb_cmd(tmp, stacks);
	else
		cmd = ft_create_rra_rb_cmd(tmp, stacks);
	return (cmd);
}
