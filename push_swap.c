#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	stack = init_stack(stack, argc, argv);
	display(stack);
	sort(stack);
	return (0);
}
