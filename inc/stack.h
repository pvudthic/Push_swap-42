#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include "inc_stdlib.h"
# include "mem_handle.h"

t_list	*init_stack(int argc, char **argv);
void	create_stack_tmp(t_list *stack);
int		convert_nb(char *str, t_list *stack);
int		stack_size(t_list *stack, char name);
t_stack	*bottom_stack(t_stack *stack);
void	check_duplicate(int nb, t_list *stack);

#endif
