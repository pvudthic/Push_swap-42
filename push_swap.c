#include "push_swap.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	t_list	*stack;

	// /* hard coding for input*/
	/*6 8 5 10 2 4 9 7 1 3*/
	argv[1] = "3";
	argv[2] = "2";
	argv[3] = "5";
	argv[4] = "0";
	argv[5] = "1";
	argv[6] = "8";
	argv[7] = "7";
	argv[8] = "6";
	argv[9] = "9";
	argv[10] = "4";
	argc = 11;

	stack = NULL;
	stack = init_stack(stack, argc, argv);
	display(stack);
	//sort(stack);
	return (0);
}
