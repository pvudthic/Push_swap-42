#include "../../push_swap.h"

/*
	Use recursive function to create add back linked list
	edge = header or footer
	index = position in stack
*/
static t_index	*add_inner_index(t_list *stack, t_stack *stack_nb,  int i)
{
	t_index	*new_index;

	if (!stack_nb)
	{
		return (NULL);
	}
	new_index = (t_index *)malloc(sizeof(t_index));
	if (!new_index)
		error_exit(stack);
	new_index->sorted = 0;
	new_index->index = i;
	if (i == 1 || !stack_nb->next)
		new_index->edge = 1;
	else
		new_index->edge = 0;
	i++;
	new_index->next = add_inner_index(stack, stack_nb->next,  i);
	return (new_index);
}

static t_index *add_header_index(t_list *stack)
{
	t_index *new_index;

	new_index = (t_index *)malloc(sizeof(t_index));
	if (!new_index)
		error_exit(stack);
	new_index->index = 0;
	new_index->sorted = 1;
	new_index->edge = 1;
	return (new_index);
}

void	initialize_index(t_list *stack)
{
	t_stack	*stack_nb;

	stack_nb = stack->a;
	stack->index_a = add_header_index(stack);
	stack->index_a->next = add_inner_index(stack, stack_nb, 1);
	stack->index_size = stack_size(stack, 'a');
	display_stack(stack);
}
