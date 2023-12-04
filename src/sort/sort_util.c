#include "push_swap.h"

/*
	Find the start
	That is last sorted before pivot
	If there was pivot
*/
int	find_start(t_stack *ref, int pivot)
{
	int		start;
	t_stack	*stack;

	stack = ref;
	start = stack->nb;
	while (stack && stack->nb != pivot)
	{
		if (stack->true_pos == 1)
			start = stack->nb;
		stack = stack->next;

	}
	return (start);
}

t_stack	*shift_start(t_stack *ref, int start)
{
	t_stack	*stack;

	stack = ref;
	while (stack)
	{
		if (stack->nb == start)
			break;
		stack = stack->next;
	}
	return (stack);
}

int	find_pivot(t_stack *ref, int start)
{
	t_stack	*stack;

	stack = shift_start(ref, start);
	while (stack->true_pos == 0)
	{
		if (!stack->next)
			break;
		else
			stack = stack->next;

	}
	return (stack->nb);
}

int	find_sort_size(t_stack *ref, int start, int pivot)
{
	t_stack	*stack;
	int		size;

	size = 1;
	stack = shift_start(ref, start);
	while (stack->nb != pivot)
	{
		size++;
		if (!stack->next)
			break;
		else
			stack = stack->next;
	}
	return (size);
}
