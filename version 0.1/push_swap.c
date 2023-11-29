#include "push_swap.h"

t_list	*initialize_stack(t_list *stack, int argc, char **argv)
{
	int		nb;

	if (argc > 0)
	{
		if (argc == 1)
			exit(0);
		stack = create_stack(argc, argv[1]);
	}
	argc--;
	while (argc > 0)
	{
		nb = parse_number(argv[argc], stack);
		if (stack->a)
			check_duplicate(nb, stack->a, stack);
		create_sa_sb(nb, stack);
		argc--;
	}
	initialize_index(stack);
	return (stack);
}

/*
	Our problem is
	1. Instruction is very unefficiency
	2. Segmentation fualt
*/
int	main(int argc, char **argv)
{
	t_list	*stack;

	// /* hard coding for input*/
	/*6 8 5 10 2 4 9 7 1 3*/

	stack = NULL;
	stack = initialize_stack(stack, argc, argv);
	sort(stack);
}
