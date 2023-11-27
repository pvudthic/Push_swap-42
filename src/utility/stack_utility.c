#include "../../push_swap.h"

t_index	*stack_start_index(t_index *index, int stack_size, int index_size)
{
	t_index *current_index;
	int		current_start;

	current_index = index;
	current_start = index_size - stack_size;
	while (current_start)
	{
		current_index = current_index->next;
		current_start--;
	}
	return (current_index);
}

/*
	if start is first index or edges index
		-> do nothing
	else -> do push to B
*/
void	to_the_top_a(t_list *stack, int start)
{
	int	n;

	if (start == 0 || start == 1)
		return ;
	n = start;
	while (n > 0)
	{
		do_pb(stack);
		n--;
	}
}

int	last_num(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		current = current->next;
	}
	return (current->nb);
}

int	stack_size(t_list *stack, char name)
{
	int		size;
	t_stack	*current;

	size = 0;
	if (name == 'a')
		current = stack->a;
	else
		current = stack->b;
	while (current->next)
	{
		size++;
		current = current->next;
		if (!current->next)
			size++;
	}
	if (name == 'a')
		stack->size_a = size;
	else if (name == 'a')
		stack->size_b = size;
	return (size);
}
