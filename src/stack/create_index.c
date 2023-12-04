#include "stack.h"
/*
	Use recursive function to create add back linked list
	edge = header or footer
	index = position in stack
*/
static t_index	*add_inner_index(t_list *stack, t_stack *stack_nb, int i)
{
	t_index	*new_index;

	if (!stack_nb)
	{
		return (NULL);
	}
	new_index = (t_index *)malloc(sizeof(t_index));
	if (!new_index)
		error_exit(stack);
	new_index->i = i;
	i++;
	new_index->next = add_inner_index(stack, stack_nb->next, i);
	return (new_index);
}

void	initialize_index(t_list *stack)
{
	t_stack	*stack_nb;

	stack_nb = stack->a;
	stack->index = add_inner_index(stack, stack_nb, 1);
}
