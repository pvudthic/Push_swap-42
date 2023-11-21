#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		nb;
	t_list	*stack;

	/* hard coding for input*/
	/*6 8 5 10 2 4 9 7 1 3*/
	argv[1] = "6";
	argv[2] = "8";
	argv[3] = "5";
	argv[4] = "10";
	argv[5] = "2";
	argv[6] = "4";
	argv[7] = "9";
	argv[8] = "7";
	argv[9] = "1";
	argv[10] = "3";
	argc = 7;
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
	sort(stack);
	return (0);
}

//Error condition for input
/*
1. empty string : "" ✘
2. NULL address : NULL ✘ result : segmentation fault
3. 1 number : "100" ✓
4. 1 character : "a" ✓
5. start with 'space' or 'double space' : " 100 1000" , "  100 1000" ✓
6. end with 'space' or 'double space' : "100 1000 " , "100 1000  " ✓
7. start and end with 'space' or 'double space' : " 100 1000 ", "  100 1000  " ✓
8. contain double space : "100  1000", "1 2  3 4  5" ✓
8. Value more than maximum- minimum int : "??" ✘
9. string contain character : "100a", "100b" ✓
10. negative number & double negative sign : "--100", "-100 --1000" ✓
11. many character : "Phanuwat Vudthichai Rangsu n \t" ✓
*/
