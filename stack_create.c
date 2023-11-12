#include "push_swap.h"

static void	first_stack_ab(int nb, t_s *stack)
{
	stack->a = (t_sa *)malloc(sizeof(stack->a));
	if (!stack->a)
		error_exit(stack);
	stack->b = (t_sb *)malloc(sizeof(stack->b));
	if (!stack->b)
		error_exit(stack);
	stack->a->nb = nb;
	stack->b->nb = 0;
	stack->a->next = NULL;
	stack->b->next = NULL;
}

t_s	*create_stack(int argc, char *first_input_arg)
{
	t_s	*stack;

	stack = NULL;
	if (argc == 2)
	{
		parse_number(first_input_arg, stack);
		exit(0);
	}
	stack = (t_s *)malloc(sizeof(t_s));
	if (!stack)
		error_exit(NULL);
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

void	create_sa_sb(int nb, t_s *stack)
{
	t_sa	*new_a;
	t_sb	*new_b;

	if (!stack->a && !stack->b)
		first_stack_ab(nb, stack);
	else
	{
		new_a = (t_sa *)malloc(sizeof(stack->a));
		if (!new_a)
			error_exit(stack);
		new_b = (t_sb *)malloc(sizeof(stack->b));
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

int	parse_number(char *str, t_s *stack)
{
	int			neg;
	long long	res;

	neg = 1;
	res = 0;
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
