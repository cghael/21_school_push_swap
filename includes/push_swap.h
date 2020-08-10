/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:57:53 by cghael            #+#    #+#             */
/*   Updated: 2020/07/14 14:57:56 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** --------------------------- Macros \ Static ---------------------------------
*/

# define USAGE_PS		"usage: ./push_swap args | ./checker args\n"
# define ERROR_EXIT		1
# define ERR_ARGS		"Error\n"
# define ERR_UNIQ_ARGS	"Error\n"
# define NOT_A_NUMB(x)	(x < 48 || x > 57)

# define SORTED			1
# define NOT_SORTED		0
# define ROTATE			1
# define REVERSE		0
# define TRUE			1
# define FALSE			0

/*
** -------------------------- External Headers ---------------------------------
*/

# include "ft_printf.h"
# include "ft_get_next_line.h"

/*
** ------------------------- Structures Definition -----------------------------
*/

typedef struct			s_elem
{
	int					value;
	int					index;
	int					stay;
	char				name;
	struct s_elem		*next;
	struct s_elem		*back;
}						t_elem;

typedef struct			s_order
{
	char				command[4];
	struct s_order		*next;
	int					step_numb;
}						t_order;

typedef struct			s_steps
{
	t_elem				*x;
	t_elem				*y;
	int					var[4];
	int					min_value;
	int					min_var;
}						t_steps;

typedef struct			s_st
{
	t_elem				*a;
	int					qnty_a;
	t_elem				*b;
	int					qnty_b;
	t_order				*cmd;
}						t_st;

typedef struct			s_flags
{
	int					visual;
	int					color;
}						t_flags;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

t_st					*ft_create_t_st_elem(void);
t_st					*ft_check_n_write_args(int argc, char **argv, int ps);
t_elem					*ft_one_agr(char **argv);
t_elem					*ft_multi_arg(char **argv, int argc);
void					ft_new_elem_add(t_elem **stack, int numb);
void					ft_free_stack(t_elem *stack);
void					ft_start_sorting(t_st **stacks);
void					ft_presort_stack(t_st **stacks);
t_steps					*ft_choose_optimal_step(t_st **stacks);
void					ft_count_steps(t_steps **stp, t_st **stacks);
void					ft_count_ra_rb(t_st **stacks, t_steps **stp);
void					ft_count_rra_rrb(t_st **stacks, t_steps **stp);
void					ft_create_cmd(t_steps *tmp, t_st **stacks);
void					ft_run_cmd(char *cmd, t_st **stacks, t_flags options);
void					ft_get_stack_back(t_st **stacks);
void					ft_min_steps_count(t_steps **tmp);
void					ft_sort_stacks(t_st **stacks);
int						ft_check_stack_sorted(t_elem *stack, int qnty);
void					ft_new_order_add(t_order **cmd_stack, char *str);
void					ft_free_cmd_stack(t_order *cmd_stack);
void					ft_print_operations(t_order *cmd_stack);
void					ft_free_push_swap_mem(t_st *stacks);
void					ft_pa_pb(t_st **stacks, char src_name);
void					ft_ra_rb(t_st **stacks, char stack_name);
void					ft_rra_rrb(t_st **stacks, char stack_name);
void					ft_rr_rrr(t_st **stacks, int side);
void					ft_sa_sb(t_st **stacks, char stack_name);
void					ft_print_stack_step(t_st *stacks, char *cmd, int color);
void					ft_sort_two_three_elem(t_st **stacks);
int						ft_max_min_int(char *str);

#endif
