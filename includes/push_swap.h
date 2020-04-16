//
// Created by Anton on 04.04.2020.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** --------------------------- Macros \ Static ---------------------------------
*/

# define USAGE "usage: ./checker target_file\n"
# define EXIT_CODE 1
# define ERR_ARGS "Error args, please use only numbers and spaces.\n"


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
t_elem					*ft_multi_arg(char **argv);
void					ft_new_elem_add(t_elem **stack, int numb);

#endif //PUSH_SWAP_H
