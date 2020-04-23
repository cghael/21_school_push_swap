//
// Created by Anton on 04.04.2020.
//

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

# define STACK_SORTED 1
# define STACK_NOT_SORTED 0



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
	int					qnty;
	char				name;
	struct s_elem		*next;
	struct s_elem		*back;
}						t_elem;

typedef struct		s_order
{
	char			command[4];
	struct s_order	*next;
	int				step_numb;
}					t_order;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

t_elem					*ft_check_n_write_args(int argc, char **argv);
t_elem					*ft_one_agr(char **argv);
t_elem					*ft_multi_arg(char **argv, int argc);
void					ft_new_elem_add(t_elem **stack, int numb);
void					ft_free_stack(t_elem *stack);

t_order					*ft_sort_stack_a(t_elem *stack_a);
int						ft_check_stack_sorted(t_elem *stack);

void					ft_new_order_add(t_order **cmd_stack, char *str);
void					ft_free_cmd_stack(t_order *cmd_stack);

void					ft_print_operations(t_order *cmd_stack);
void					ft_free_push_swap_mem(t_order *cmd_stack,\
												t_elem *stack_a);

void					ft_pa_pb(t_order **cmd_stack, t_elem **src_stack, \
								t_elem **dst_stack, char dst_ch);
void					ft_ra_rb(t_order **cmd_stack, t_elem **stack, char ch);
void					ft_print_stack_step(t_elem *stack_a, t_elem *stack_b);
void					ft_push_to_b_after_pivot(t_order **cmd_stack, \
											t_elem **stack_a, t_elem **stack_b);

#endif //PUSH_SWAP_H
