#include "stack.h"

void	mem_alloc(int nb, t_list *stack)
{
	t_stack	*new_a;
	t_stack	*new_tmp;

	new_a = (t_stack *)malloc(sizeof(t_stack));
	if (!new_a)
		error_exit(stack);
	new_tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!new_tmp)
		error_exit(stack);
	new_a->nb = nb;
	new_tmp->nb = nb;
	new_a->sort = 0;
	new_tmp->sort = 0;
	new_a->position = 1;
	new_tmp->position = 1;
	new_a->range = 1;
	new_a->next = stack->a;
	new_tmp->next = stack->tmp;
	stack->a = new_a;
	stack->tmp = new_tmp;
}

int	parse_number(char *str, t_list *stack)
{
	int			neg;
	long long	res;

	neg = 1;
	res = 0;
	if (*str == '\0')
		error_exit(stack);
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
			error_exit(stack);
		if (*str == '-' || *str == '+')
		{
			if (*(str + 1) < '0' || *(str + 1) > '9')
				error_exit(stack);
			if (*str == '-')
				neg = -1;
			str++;
		}
		res = (*str - '0') + (res * 10);
		if (res < INT_MIN || res > INT_MAX)
			error_exit(stack);
		str++;
	}
	return ((int)(res * neg));
}

t_list	*create_stack(int argc, char *first_input_arg)
{
	t_list	*stack;

	stack = NULL;
	if (argc == 2)
	{
		parse_number(first_input_arg, stack);
		exit(0);
	}
	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		error_exit(NULL);
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
	stack->index = NULL;
	return (stack);
}

t_list	*init_stack(t_list *stack, int argc, char **argv)
{
	int		nb;

	if (argc <= 1)
		exit(0);
	stack = create_stack(argc, argv[1]);
	argc--;
	while (argc > 0)
	{
		nb = parse_number(argv[argc], stack);
		if (stack->a)
			check_duplicate(nb, stack);
		mem_alloc(nb, stack);
		argc--;
	}
	//initialize_index(stack);
	return (stack);
}
