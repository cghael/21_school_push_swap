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
	struct s_elem		*next;
	struct s_elem		*back;
}						t_elem;

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

#endif //PUSH_SWAP_H
