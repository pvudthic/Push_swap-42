#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;

	// argv[1] = "1";
	// argv[2] = "2";
	// argv[3] = "4";
	// argv[4] = "0";
	// argv[5] = "10";
	// argv[6] = "7";
	// argv[7] = "8";
	// // argv[8] = "6";
	// // argv[9] = "9";
	// // argv[10] = "4";
	// argc = 8;
	stack = NULL;
	stack = init_stack(stack, argc, argv);
	display(stack);
	sort(stack);
	return (0);
}
