#include "push_swap.h"

void	partition_pos1(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = minimum(stack->a, size) + (size / 3);
	pivot_2 = minimum(stack->a, size) + (size / 3) * 2;
	while (size)
	{
		if (stack->top_a->nb < pivot_2)
		{
			if (stack->top_a->nb < pivot_1)
				move_1_to_(stack, max_range, 4);
			else
				move_1_to_(stack, max_range, 2);
		}
		else
			move_1_to_(stack, max_range, 3);
		size--;
	}
}

void	partition_pos2(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = minimum(stack->b, size) + (size / 3);
	pivot_2 = minimum(stack->b, size) + (size / 3) * 2;
	while (size)
	{
		if (stack->top_b->nb < pivot_2)
		{
			if (stack->top_b->nb < pivot_1)
				move_2_to_(stack, max_range, 4);
			else
				move_2_to_(stack, max_range, 3);
		}
		else
			move_2_to_(stack, max_range, 1);
		size--;
	}
}

void	partition_pos3(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = minimum(stack->range_stack, size) + (size / 3);
	pivot_2 = minimum(stack->range_stack, size) + (size / 3) * 2;
	while (size)
	{
		if (stack->bottom_a->nb < pivot_2)
		{
			if (stack->bottom_a->nb < pivot_1)
				move_3_to_(stack, max_range, 4);
			else
				move_3_to_(stack, max_range, 2);
		}
		else
			move_3_to_(stack, max_range, 1);
		size--;
	}
}

void	partition_pos4(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = minimum(stack->range_stack, size) + (size / 3);
	pivot_2 = minimum(stack->range_stack, size) + (size / 3) * 2;
	while (size)
	{
		if (stack->bottom_b->nb < pivot_2)
		{
			if (stack->bottom_b->nb < pivot_1)
				move_4_to_(stack, max_range, 2);
			else
				move_4_to_(stack, max_range, 3);
		}
		else
			move_4_to_(stack, max_range, 1);
		size--;
	}
}

void	first_partition(t_list *stack)
{
	int	max_range;

	max_range = 1;
	while (stack->size_a >= 4)
	{
		partition_pos1(stack, stack->size_a, max_range);
		max_range += 2;
	}
	base_sort_new(stack, stack->size_a, 1);
	stack->max_range = max_range;
}
