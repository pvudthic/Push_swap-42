#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

typedef struct a_list
{
	int				nb;
	int				position;
	int				range;
	int				sort;
	struct a_list	*next;
	struct a_list	*prev;
}	t_stack;

typedef struct i_list
{
	int				i;
	struct i_list	*next;
}	t_index;

typedef struct l_list
{
	int		pivot;
	int		max_range;
	int		t_size;
	int		size_a;
	int		size_b;
	int		n_1;
	int		n_2;
	int		n_3;
	t_stack	*a;
	t_stack	*b;
	t_stack	*top_a;
	t_stack	*bottom_a;
	t_stack	*top_b;
	t_stack	*bottom_b;
	t_stack	*tmp;
	t_stack	*range_stack;
}	t_list;

t_list	*init_stack(t_list *stack, int argc, char **argv);
void	init_value(t_list *stack, t_stack *new_a, t_stack *new_tmp, int nb);
void	init_position(t_list *stack);
int		stack_size(t_list *stack, char name);
int		last_num(t_stack *stack);
t_stack	*bottom_stack(t_stack *stack);

#endif
