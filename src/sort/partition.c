#include "push_swap.h"

t_stack	*start_stack(t_stack *stack, int max_range)
{
	t_stack *current;

	current = stack;
	while (current)
	{
		if (current->range == max_range)
			break;
		current = current->next;
	}
	return (current);
}

/*
	We should  collect && update of
		addres of last stack
		or addrest of first stack
	When rotate, push, swap happen
	in stack
	becuase it easy to use when we compare number
*/

int	partition_pos4(t_list *stack, int size, int max_range)
{
	int		pivot_1;
	int		pivot_2;
	t_stack	*current;

	exit(0);
	current = start_stack(stack->b, max_range);
	pivot_1 = minimum(current, size) + (size / 3);
	pivot_2 = minimum(current, size) + (size / 3) * 2;
	printf("pv1:%d, pv2:%d\n", pivot_1, pivot_2);
	while (size)
	{
		/*It will the last number we should try another collect address*/
		size--;
	}
	return (max_range + 2);
}

int	partition_pos1(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = minimum(stack->a, size) + (size / 3);
	pivot_2 = minimum(stack->a, size) + (size / 3) * 2;
	printf("pv1:%d, pv2:%d\n", pivot_1, pivot_2);
	while (size)
	{
		if (stack->a->nb < pivot_2)
		{
			if (stack->a->nb < pivot_1)
			{
				stack->a->position = 4;
				stack->a->range = max_range;
				do_pb(stack);
				do_rb(stack);
			}
			else
			{
				stack->a->position = 2;
				stack->a->range = max_range + 1;
				do_pb(stack);
			}
		}
		else
		{
			stack->a->position = 3;
			stack->a->range = max_range + 2;
			do_ra(stack);
		}
		size--;
	}
	display(stack);
	return (max_range + 2);
}

int	partition_pos2(t_list *stack, int size, int max_range)
{
	int	pivot_1;
	int	pivot_2;

	pivot_1 = minimum(stack->b, size) + (size / 3);
	pivot_2 = minimum(stack->b, size) + (size / 3) * 2;
	printf("pv1:%d, pv2:%d\n", pivot_1, pivot_2);
	while (size)
	{
		if (stack->b->nb < pivot_2)
		{
			if (stack->b->nb < pivot_1)
			{
				stack->b->position = 4;
				stack->b->range = max_range;
				do_rb(stack);
			}
			else
			{
				stack->b->position = 3;
				stack->b->range = max_range + 1;
				do_pa(stack);
				do_ra(stack);
			}
		}
		else
		{
			stack->b->position = 1;
			stack->b->range = max_range + 2;
			do_pa(stack);
		}
		size--;
	}
	display(stack);
	return (max_range + 2);
}

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

void	first_partition(t_list *stack, int max_range)
{
	int	size;
	int	pivot_1;
	int	pivot_2;

	display(stack);
	size = stack_size(stack, 'a');
	printf("size: %d\n", size);
	if (size <= 4)
	{
		base_sort(stack, size, 1, 'a');
		stack->max_range = max_range;
		return ;
	}
	pivot_1 = minimum(stack->a, size) + (size / 3);
	pivot_2 = minimum(stack->a, size) + (size / 3) * 2;
	printf("pv1:%d , pv2:%d\n", pivot_1, pivot_2);
	while (size)
	{
		if (stack->a->nb < pivot_2)
		{
			if (stack->a->nb < pivot_1)
			{
				stack->a->position = 4;
				stack->a->range = max_range;
				do_pb(stack);
				do_rb(stack);
			}
			else
			{
				stack->a->position = 2;
				stack->a->range = max_range + 1;
				do_pb(stack);
			}
		}
		else
		{
			stack->a->position = 3;
			stack->a->range = max_range + 2;
			do_ra(stack);
		}
		size--;
	}
	first_partition(stack, max_range + 2);
}
