#include "push_swap.h"

int	find_next(t_stack *marker)
{
	if (marker->next)
	{
		marker = marker->next;
		return (marker->nb);
	}
	return (marker->nb);
}

int	find_prev(t_stack *ref, t_stack *marker)
{
	t_stack	*stack_tmp;

	stack_tmp = ref;
	if (stack_tmp == marker)
		return (stack_tmp->nb);
	while (stack_tmp)
	{
		if (stack_tmp->next == marker)
			return (stack_tmp->nb);
		stack_tmp = stack_tmp->next;
	}
	return (stack_tmp->nb);
}
