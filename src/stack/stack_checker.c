#include "../../push_swap.h"

bool empty_b(t_list *stack)
{
	t_stack *current;

	current = stack->a;
	if (!current)
		return (true);
	else
		return (false);
}

bool is_sort(t_list *stack)
{
	t_stack *current;

	current = stack->a;
	while (current->next != NULL)
	{
		if (current->nb > current->next->nb)
			return (false);
		current = current->next;
	}
	// If the loop completes without returning false, the stack is sorted.
	return (true);
}
