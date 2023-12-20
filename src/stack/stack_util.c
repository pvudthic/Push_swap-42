#include "stack.h"
#include <stdio.h>

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

int	last_num(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		current = current->next;
	}
	return (current->nb);
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

void	init_value(t_list *stack, t_stack *new_a, t_stack *new_tmp, int nb)
{
	t_stack	*bottom;

	new_a->nb = nb;
	new_tmp->nb = nb;
	new_a->sort = 0;
	new_tmp->sort = 0;
	new_a->position = 1;
	new_tmp->position = 1;
	new_a->range = 1;
	bottom = stack->a;
	new_tmp->next = stack->tmp;
	stack->a = new_a;
	stack->a->next = bottom;
	stack->tmp = new_tmp;
}

void	init_position(t_list *stack)
{
	stack->t_size = stack_size(stack, 'a');
	stack->top_a = stack->a;
	stack->bottom_a = bottom_stack(stack->a);
	stack->top_b = NULL;
	stack->bottom_b = NULL;
	stack->size_a = stack->t_size;
	stack->size_b = 0;
}
