#include "push_swap.h"

int	minimum(t_stack *ref)
{
	int	minimum;
	t_stack	*stack;

	stack = ref;
	minimum = stack->nb;
	while (stack)
	{
		if (minimum > stack->nb)
			minimum = stack->nb;
		stack = stack->next;
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
		base_sort(stack, size);
		stack->max_range = max_range;
		return ;
	}
	pivot_1 = minimum(stack->a) + (size / 3);
	pivot_2 = minimum(stack->a) + (size / 3) * 2;
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

char	find_stack(t_list *ref, int max_range)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ref->a;
	stack_b = ref->b;
	while (stack_a)
	{
		if (stack_a->range == max_range)
			return ('a');
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		if (stack_b->range == max_range)
			return ('b');
		stack_b = stack_b->next;
	}
	return ('n');
}

bool	is_sort(t_list *ref, char name, int max_range)
{
	t_stack *current;

	if (name == 'a')
		current = ref->a;
	else
		current = ref->b;
	while (current->next != NULL)
	{
		if ((current->nb > current->next->nb) && current->range == max_range)
			return (false);
		current = current->next;
	}
	// If the loop completes without returning false, the stack is sorted.
	return (true);
}



void	sort(t_list *stack)
{
	int		max_range;
	char	stack_name;

	create_rank(stack);
	first_partition(stack, 1);
	max_range = stack->max_range;
	display(stack);
	while (max_range)
	{
		printf("max_range == %d\n", max_range);
		stack_name = find_stack(stack, max_range);
		printf("stack_name: %c\n", stack_name);
		if (!is_sort(stack, stack_name, max_range))
		{
			printf("sort that stack!!\n");
		}
		else
			printf("range:%d has sorted!\n", max_range);
		max_range--;
	}
}
