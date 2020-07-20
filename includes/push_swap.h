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

# define USAGE_PUSH_SWAP	"usage: ./push_swap args\n"
# define ERROR_EXIT_CODE	1
# define ERR_ARGS			"Error. Please, use only numbers and spaces.\n"
# define ERR_UNIQ_ARGS		"Error. Please, enter UNIQUE args and try again.\n"
# define NOT_A_NUMBER(x)	(x < 48 || x > 57)

# define SORTED				1
# define NOT_SORTED			0
# define ROTATE				1
# define REVERSE			0

/*
** -------------------------- External Headers ---------------------------------
*/

# include "ft_printf.h"
# include "libft.h"

/*
** ------------------------- Structures Definition -----------------------------
*/

typedef struct			s_elem
{
	int 				value;
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

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

t_st					*ft_create_t_st_elem(void);
t_st					*ft_check_n_write_args(int argc, char **argv);
t_elem					*ft_one_agr(char **argv);
t_elem					*ft_multi_arg(char **argv, int argc);
void					ft_new_elem_add(t_elem **stack, int numb);
void					ft_free_stack(t_elem *stack);

void					ft_start_sorting(t_st **stacks);
void					ft_presort_stack(t_st **stacks);
void					ft_move_elem_to_b(t_st **stacks, int piece);
t_steps*				ft_choose_optimal_step(t_st **stacks);
void					ft_count_steps(t_steps **stp, t_st **stacks);
void					ft_count_ra_rb(t_st **stacks, t_steps **stp);
void					ft_count_rra_rrb(t_st **stacks, t_steps **stp);
//void					ft_run_min_steps(t_steps *tmp, t_st **stacks);
void					ft_create_cmd(t_steps *tmp, t_st **stacks);
void					ft_run_cmd(char *cmd, t_st **stacks);
void					ft_get_stack_back(t_st **stacks);
void					ft_delete_t_steps(t_steps *tmp);
void					ft_min_steps_count(t_steps **tmp);
int						ft_steps_to_move_current_on_top_b(t_elem *current, t_st *stacks);
int						ft_steps_ready_stack_a_to_push_current(t_elem *cur, t_st *stacks);
//void					ft_push_tmp_to_a(t_st **stacks, t_elem *tmp);
//int						ft_need_steps_to_push(t_elem *current, t_st *stacks);
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
void					ft_print_stack_step(t_st *stacks);
//int						ft_push_to_dst_before_pivot(t_order **cmd, t_elem **src, \
//														t_elem **dst, int move);
//t_elem					*ft_adjust_big_to_small_stack(t_order **cmd_stack, \
//											t_elem **stack, int index);
//int						ft_find_rotate_side(t_elem *stack, int piece);
//int						ft_nearest_smaller_pivot(t_elem *stack, int pivot);
void					ft_sort_two_three_elem(t_st **stacks);
//void					ft_sort_last_step(t_order **cmd, t_elem **src, int step);
//int						ft_find_pivot(t_elem *src, int move);
//int						ft_side_to_rotate(int pivot, t_elem **src);

#endif
