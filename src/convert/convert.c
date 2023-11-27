#include "../../push_swap.h"

/*
	This is a simple function that
		recieve number in stack
		then
		find return that index
*/
int		find_index(t_index *index, t_stack *stack, int nb)
{
	t_index	*c_index;
	t_stack	*c_stack;

	c_index = index;
	c_stack = stack;
	while (c_stack)
	{
		if (c_stack->nb == nb)
			break;
		c_stack = c_stack->next;
		c_index = c_index->next;
	}
	return (c_index->index);
}

int	find_value(t_list *stack, int start)
{
	int		value;
	t_stack *c_stack;
	t_index *c_index;

	if (start == 0)
		start = 1;
	c_stack = stack->a;
	c_index = stack_start_index(stack->index_a, stack->size_a, stack->index_size);
	value = c_stack->nb;
	while (c_index)
	{
		if (c_index->index == start)
			break;
		value = c_stack->nb;
		c_index = c_index->next;
		c_stack = c_stack->next;
	}
	return (value);
}
