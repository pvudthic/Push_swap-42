#include "stack.h"
#include "free_mem.h"
#include <stdio.h>

static void	check_duplicate(int nb, t_list *stack)
{
	t_stack	*head_stack;

	head_stack = stack->a;
	while (head_stack)
	{
		if (nb == head_stack->nb)
		{
			error_exit(stack);
		}
		head_stack = head_stack->next;
	}
}

static void	alloc_a_b(int nb, t_list *stack)
{
	t_stack	*new_a;
	t_stack	*new_tmp;

	new_a = NULL;
	new_tmp = NULL;
	new_a = (t_stack *)malloc(sizeof(t_stack));
	if (!new_a)
		error_exit(stack);
	new_tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!new_tmp)
		error_exit(stack);
	init_value(stack, new_a, new_tmp, nb);
}

static int	parse_number(char *str, t_list *stack)
{
	int			neg;
	long long	res;

	neg = 1;
	res = 0;
	if (*str == '\0')
		error_exit(stack);
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) < '0' || *(str + 1) > '9')
			error_exit(stack);
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str)
	{
		if ((*str < '0' || *str > '9'))
			error_exit(stack);
		res = (*str - '0') + (res * 10);
		if ((res * neg) < INT_MIN || (res * neg) > INT_MAX)
			error_exit(stack);
		str++;
	}
	return ((int)(res * neg));
}

static t_list	*alloc_list(void)
{
	t_list	*stack;

	stack = NULL;
	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		error_exit(NULL);
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
	return (stack);
}

t_list	*init_stack(t_list *stack, int argc, char **argv)
{
	int		nb;
	char	**data;
	char	**head;

	if (!*argv[1])
		error_exit(0);
	stack = alloc_list();
	argc--;
	while (argc > 0)
	{
		data = split_to_stack(stack, argv[argc]);
		head = data;
		while (*head)
		{
			nb = parse_number(*head, stack);
			if (stack->a)
				check_duplicate(nb, stack);
			alloc_a_b(nb, stack);
			head++;
		}
		data = free_split(data);
		argc--;
	}
	init_position(stack);
	return (stack);
}
