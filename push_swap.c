#include "push_swap.h"

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
	//display(stack);
	sort(stack);
	return (0);
}
