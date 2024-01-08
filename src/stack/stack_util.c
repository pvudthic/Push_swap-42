#include "stack.h"

void	create_stack_tmp(t_list *stack)
{
	t_stack *stack_a;

	stack_a = stack->a;
	while (stack_a)
	{
		stack->tmp = alloc_stack(stack, stack->tmp, stack_a->nb);
		stack_a = stack_a->next;
	}
}

int	convert_nb(char *str, t_list *stack)
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

t_stack	*bottom_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

int	stack_size(t_list *stack, char name)
{
	int		size;
	t_stack	*current;

	size = 0;
	if (name == 'a')
		current = stack->a;
	else
		current = stack->b;
	while (current->next)
	{
		size++;
		current = current->next;
		if (!current->next)
			size++;
	}
	return (size);
}

void	check_duplicate(int nb, t_list *stack)
{
	t_stack	*head_stack;

	if (!stack->a)
		return ;
	head_stack = stack->a;
	while (head_stack)
	{
		if (nb == head_stack->nb)
			error_exit(stack);
		head_stack = head_stack->next;
	}
}
