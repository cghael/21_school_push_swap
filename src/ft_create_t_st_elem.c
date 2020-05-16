//
// Created by Anton on 16.05.2020.
//

#include "push_swap.h"

t_st	*ft_create_t_st_elem(void)
{
	t_st	*new;

	new = malloc(sizeof(t_st));
	if (new == NULL)
		ft_error_exit("Error malloc in ft_create_t_st_elem\n", new);
	return (new);
}