#include "push_swap.h"

void	add_stack_AB(int nb, s_list *stack)
{
	stack->a = (a_list *)malloc(sizeof(stack->a));
	if (!stack->a)
			error_exit(stack);
	stack->b =(b_list *)malloc(sizeof(stack->b));
	if (!stack->b)
		error_exit(stack);
	stack->a->nb = nb;
	stack->b->nb = 0;
	stack->a->next = NULL;
	stack->b->next = NULL;
}

void	create_stack(int nb, s_list *stack)
{
	a_list	*new_a;
	b_list	*new_b;

	if (!stack->a && !stack->b)
		add_stack_AB(nb, stack);
	else
	{
		new_a = (a_list *)malloc(sizeof(stack->a));
		if (!new_a)
			error_exit(stack);
		new_b = (b_list *)malloc(sizeof(stack->b));
		if (!new_b)
			error_exit(stack);
		new_a->nb = nb;
		new_b->nb = 0;
		new_a->next = stack->a;
		new_b->next = stack->b;
		stack->a = new_a;
		stack->b = new_b;
	}
}

int	parse_number(char *str, s_list *stack)
{
	int			neg;
	long long	res;

	neg = 1;
	res = 0;
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '-')
			error_exit(stack);
		if (*str == '-')
		{
			neg = -1;
			str++;
		}
		res = (*str - '0') + (res * 10);
		if (res < INT_MIN || res > INT_MAX)
			error_exit(stack);
		str++;
	}
	return (int)(res * neg);
}

int	main(int argc, char **argv)
{
	int		nb;
	s_list	*stack;

	argc--;
	if (argc > 0)
	{
		stack = (s_list *)malloc(sizeof(s_list));
		if (!stack)
			error_exit(NULL);
		stack->a = NULL;
		stack->b = NULL;
	}
	while (argc > 0)
	{
		nb = parse_number(argv[argc], stack);
		create_stack(nb, stack);
		argc--;
	}
	display_stack(stack);
	return 0;
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
