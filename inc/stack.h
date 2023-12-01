#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

/// This should be deleted//
# include <stdio.h>

typedef struct a_list
{
	int				nb;
	struct a_list	*next;
}	t_stack;

typedef struct i_list
{
	int				i;
	struct i_list	*next;
}	t_index;

typedef struct l_list
{
	t_stack	*a;
	t_stack	*b;
	t_index	*index;
}	t_list;

t_list	*init_stack(t_list *stack, int argc, char **argv);
t_list	*create_stack(int argc, char *first_input_arg);
int		parse_number(char *str, t_list *stack);
void	check_duplicate(int nb, t_list *stack);
void	create_sa_sb(int nb, t_list *stack);
void	initialize_index(t_list *stack);

/*Utillitys*/
void	error_exit(t_list *stack);
void	free_stack_ab(t_list *stack);
void	free_index_ab(t_list *stack);

#endif
