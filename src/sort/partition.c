#include "push_swap.h"

/*
	We should do partition for each position
		Partition in the circular partition on each range
		for most effiences way to instruction operation.
*/
int	minimum(t_stack *ref, int size)
{
	int	minimum;
	t_stack	*stack;

	stack = ref;
	minimum = stack->nb;
	while (size)
	{
		if (minimum > stack->nb)
			minimum = stack->nb;
		stack = stack->next;
		size--;
	}
	return (minimum);
}

void	pos1_to_4(t_list *stack, int max_range)
{
	stack->top_a->position = 4;
	stack->top_a->range = max_range;
	do_pb(stack);
	do_rb(stack);
}

void	pos1_to_2(t_list *stack, int max_range)
{
	stack->top_a->position = 2;
	stack->top_a->range = max_range + 1;
	do_pb(stack);
}

void	pos1_to_3(t_list *stack, int max_range)
{
	stack->top_a->position = 3;
	stack->top_a->range = max_range + 2;
	do_ra(stack);
}

void	pos2_to_1(t_list *stack, int max_range)
{
	stack->top_b->position = 1;
	stack->top_b->range = max_range + 2;
	do_pa(stack);
}

void	pos2_to_3(t_list *stack, int max_range)
{
	stack->top_b->position = 3;
	stack->top_b->range = max_range + 1;
	do_pa(stack);
	do_ra(stack);
}

void	pos2_to_4(t_list *stack, int max_range)
{
	stack->top_b->position = 4;
	stack->top_b->range = max_range;
	do_rb(stack);
}

void	pos3_to_1(t_list *stack, int max_range)
{
	stack->bottom_a->position = 1;
	stack->bottom_a->range = max_range + 2;
	do_rra(stack);
}

void	pos3_to_2(t_list *stack, int max_range)
{
	stack->bottom_a->position = 2;
	stack->bottom_a->range = max_range + 1;
	do_rra(stack);
	do_pb(stack);
}

void	pos3_to_4(t_list *stack, int max_range)
{
	stack->bottom_a->position = 4;
	stack->bottom_a->range = max_range;
	do_rra(stack);
	do_pb(stack);
	do_rb(stack);
}

void	pos4_to_1(t_list *stack, int max_range)
{
	stack->bottom_b->position = 1;
	stack->bottom_b->range = max_range + 2;
	do_rrb(stack);
	do_pa(stack);
}

void	pos4_to_3(t_list *stack, int max_range)
{
	stack->bottom_b->position = 3;
	stack->bottom_b->range = max_range + 1;
	do_rrb(stack);
	do_pa(stack);
	do_ra(stack);
}

void	pos4_to_2(t_list *stack, int max_range)
{
	stack->bottom_b->position = 2;
	stack->bottom_b->range = max_range;
	do_rrb(stack);
}

void	partition_pos1(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = minimum(stack->a, size) + (size / 3);
	pivot_2 = minimum(stack->a, size) + (size / 3) * 2;
	//printf("pv1_%d : pv2_%d\n", pivot_1, pivot_2);
	while (size)
	{
		if (stack->top_a->nb < pivot_2)
		{
			if (stack->top_a->nb < pivot_1)
				pos1_to_4(stack, max_range);
			else
				pos1_to_2(stack, max_range);
		}
		else
			pos1_to_3(stack, max_range);
		size--;
	}

}

void	partition_pos2(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = minimum(stack->b, size) + (size / 3);
	pivot_2 = minimum(stack->b, size) + (size / 3) * 2;
	//printf("pv1_%d : pv2_%d\n", pivot_1, pivot_2);
	while (size)
	{
		if (stack->top_b->nb < pivot_2)
		{
			if (stack->top_b->nb < pivot_1)
				pos2_to_4(stack, max_range);
			else
				pos2_to_3(stack, max_range);
		}
		else
			pos2_to_1(stack, max_range);
		size--;
	}
}

void	partition_pos3(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = minimum(stack->range_stack, size) + (size / 3);
	pivot_2 = minimum(stack->range_stack, size) + (size / 3) * 2;
	//printf("pv1_%d : pv2_%d\n", pivot_1, pivot_2);
	while (size)
	{
		if (stack->bottom_a->nb < pivot_2)
		{
			if (stack->bottom_a->nb < pivot_1)
				pos3_to_4(stack, max_range);
			else
				pos3_to_2(stack, max_range);
		}
		else
			pos3_to_1(stack, max_range);
		size--;
	}
}

void	partition_pos4(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	//display_position(stack);
	pivot_1 = minimum(stack->range_stack, size) + (size / 3);
	pivot_2 = minimum(stack->range_stack, size) + (size / 3) * 2;
	//printf("pv1_%d : pv2_%d\n", pivot_1, pivot_2);
	while (size)
	{
		if (stack->bottom_b->nb < pivot_2)
		{
			if (stack->bottom_b->nb < pivot_1)
				pos4_to_2(stack, max_range);
			else
				pos4_to_3(stack, max_range);
		}
		else
			pos4_to_1(stack, max_range);
		size--;
	}
}

void	first_partition(t_list *stack)
{
	int	max_range;

	max_range = 1;
	while (stack->size_a > 4)
	{
		partition_pos1(stack, stack->size_a, max_range);
		max_range += 2;
	}
	//display(stack);
	base_sort(stack, stack->size_a, 1);
	stack->max_range = max_range;
	//display(stack);
	//display_position(stack);
}
