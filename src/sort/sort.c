#include "push_swap.h"

int	range_size(t_stack *stack, int max_range)
{
	int		size;
	t_stack *current;

	size = 0;
	current = stack;
	while (current)
	{
		if (current->range == max_range)
			size++;
		current = current->next;
	}
	return (size);
}

int	find_position(t_stack *stack, int max_range)
{
	t_stack *current;

	current = stack;
	while (current)
	{
		if (current->range == max_range)
			break;
		current = current->next;
	}
	return (current->position);
}

int	position_partition(t_list *stack, int size, int position, int max_range)
{
	if (position == 1)
	{
		return (partition_pos1(stack, size, max_range));
	}
	if (position == 2)
	{
		return (partition_pos2(stack, size, max_range));
	}
	if (position == 4)
	{
		return (partition_pos4(stack, size, max_range));
	}
	return (0);
}

int	range_sort(t_list *ref, int max_range, char stack_name)
{
	int		size;
	int		position;
	t_stack	*stack;

	if (stack_name == 'a')
		stack = ref->a;
	else
		stack = ref->b;
	size = range_size(stack, max_range);
	position = find_position(stack, max_range);
	printf(">>>position :: %d\n", position);
	if (size <= 4)
	{
		base_sort(ref, size, position, stack_name);
		return (max_range - 1);
	}
	else
	{
		max_range = position_partition(ref, size, position, max_range);
	}
	return (max_range);
}

void	sort(t_list *stack)
{
	int		max_range;
	char	stack_name;

	create_rank(stack);
	first_partition(stack, 1);
	max_range = stack->max_range - 1;
	display(stack);
	while (max_range)
	{
		printf("max_range == %d\n", max_range);
		stack_name = find_stack_name(stack, max_range);
		printf("stack_name: %c\n", stack_name);
		max_range = range_sort(stack, max_range, stack_name);
		display(stack);
	}
}
