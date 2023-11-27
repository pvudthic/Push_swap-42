#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/// This should be deleted//
# include <stdio.h>
///////////////////////////

typedef struct a_list
{
	int				nb;
	struct a_list	*next;
}	t_stack;

typedef struct i_list
{
	int				index;
	int				sorted;
	int				edge;
	struct i_list	*next;
}	t_index;

typedef struct l_list
{
	int		error;
	int		size_a;
	int		size_b;
	int		index_size;
	t_stack	*a;
	t_stack	*b;
	t_index	*index_a;
	t_index	*index_b;
}	t_list;

/*         display stack         */
void	display_stack(t_list *stack);

/*        stack operation        */
void	do_sa(t_list *stack);
void	do_sb(t_list *stack);
void	do_ss(t_list *stack);
void	do_pa(t_list *stack);
void	do_pb(t_list *stack);
void	do_ra(t_list *stack);
void	do_rb(t_list *stack);
void	do_rr(t_list *stack);
void	do_rra(t_list *stack);
void	do_rrb(t_list *stack);
void	do_rrr(t_list *stack);

/*            sorting            */
void	sort(t_list *stack);

/*         create stack         */
void	initialize_index(t_list *stack);
void	create_sa_sb(int nb, t_list *stack);
t_list	*create_stack(int argc, char *first_input_arg);
int		parse_number(char *str, t_list *stack);

/*           utility           */
void	free_stack_ab(t_list *stack);
void	check_duplicate(int nb, t_stack *stack_a, t_list *stack);
void	error_exit(t_list *stack);

/*stack utility*/
int		last_num(t_stack *stack);
int		stack_size(t_list *stack, char name);
t_index	*stack_start_index(t_index *index, int stack_size, int index_size);
void	to_the_top_a(t_list *stack, int start);

/*complementary*/
void	down_swap(t_list *stack, int target, int marker);
void	up_swap(t_list *stack, int target, int marker);

/*convert*/
int		find_index(t_index *index, t_stack *stack, int nb);
int		find_value(t_list *stack, int start);

/*             main            */
int		main(int argc, char **argv);

#endif
