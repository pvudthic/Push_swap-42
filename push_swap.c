#include "push_swap.h"

static bool	is_sort(t_list *ref)
{
	t_stack *current;

	current = ref->a;
	while (current->next != NULL)
	{
		if ((current->nb > current->next->nb))
			return (false);
		current = current->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	stack = init_stack(stack, argc, argv);
	stack->top_a = stack->a;
	stack->top_b = NULL;
	stack->bottom_a = bottom_stack(stack->a);
	stack->bottom_b = NULL;
	stack->size_a = stack_size(stack, 'a');
	stack->size_b = 0;
	if (!is_sort(stack))
	{
		if (stack->size_a == 2)
			compare_swap(stack, 3);
		else if (stack->size_a == 3)
			sort3_easy(stack);
		else if (stack->size_a > 3 && stack->size_a <= 5)
			sort4_5_easy(stack);
		else
			sort(stack);
	}
	free_stack_ab(stack);
}
