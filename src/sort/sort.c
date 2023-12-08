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

int	find_position(t_list *stack, int max_range)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack->a;
	stack_b = stack->b;
	while (stack_a)
	{
		if (stack_a->range == max_range)
		{
			stack->range_stack = stack_a;
			return (stack_a->position);
		}
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		if (stack_b->range == max_range)
		{
			stack->range_stack = stack_b;
			return (stack_b->position);
		}
		stack_b = stack_b->next;
	}
	return (0);
}

int	position_partition(t_list *stack, int size, int position, int max_range)
{
	if (position == 1)
		partition_pos1(stack, size, max_range);
	else if (position == 2)
		partition_pos2(stack, size, max_range);
	else if (position == 3)
		partition_pos3(stack, size, max_range);
	else if (position == 4)
		partition_pos4(stack, size, max_range);
	return (max_range + 2);
}

int	range_sort(t_list *ref, int max_range, int position)
{
	int		size;
	t_stack	*stack;

	if (position == 1 || position == 3)
		stack = ref->a;
	else
		stack = ref->b;
	size = range_size(stack, max_range);
	//printf(">>>position : %d >>>size : %d\n", position, size);
	if (size <= 4)
	{
		base_sort(ref, size, position);
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
	int		position;
	int		max_range;

	create_rank(stack);
	//display(stack);
	first_partition(stack);
	max_range = stack->max_range - 1;
	while (max_range)
	{
		//printf("max_range == %d  ", max_range);
		position = find_position(stack, max_range);
		//printf("stack position: %d\n", position);
		max_range = range_sort(stack, max_range, position);
		//display(stack);
	}
	//printf("All should be sort!!\n");

}
