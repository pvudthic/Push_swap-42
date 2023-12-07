#include "stack.h"

t_stack	*bottom_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
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
	return (size);
}
