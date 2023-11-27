#include "../../push_swap.h"

int		find_value(t_stack *stack, t_index *index, int target_index)
{
	t_index *c_index;
	t_stack *c_stack;
	int		n;

	if (target_index == 0)
		target_index = 1;
	n = 1;
	c_index = index->next;
	c_stack = stack;
	while (n != target_index)
	{
		c_index = c_index->next;
		c_stack = c_stack->next;
		n++;
	}
	return c_stack->nb;
}

void	to_top_a(t_list *stack, int marker)
{
	if (marker > 1)
	{
		do_pb(stack);
		display(stack);
	}
}

void	bottom_swap(t_list *stack, int target, int size)
{
	int	n;

	n = 0;
	printf("bottom swap\n");
	while (n < (size - target))
	{
		do_rra(stack);
		do_pb(stack);
		n++;
	}
	do_rra(stack);
	do_sa(stack);
	do_ra(stack);
	n = 0;
	while (n < (size - target))
	{
		do_pa(stack);
		do_ra(stack);
		n++;
	}
}

void	top_swap(t_list *stack, int target, int size)
{
	int	n;

	n = 0;
	printf("top swap\n");
	do_pb(stack);
	while (n < target - 2)
	{
		do_ra(stack);
		n++;
	}
	do_pa(stack);
	do_sa(stack);
	do_pb(stack);
	n = 0;
	while (n < target - 2)
	{
		do_rra(stack);
		n++;
	}
	do_pa(stack);
}

void	swap(t_list *stack, int target)
{
	int	size;

	size =stack_size(stack, 'a');
	if (target == 2)
		do_sa(stack);
	else if (target > (size / 2))
	{
		bottom_swap(stack, target, size);
	}
	else if (target <= (size / 2))
	{
		top_swap(stack, target, size);
	}
	display(stack);
}

void	quick_sort(t_list *stack, int pivot, int marker, int index)
{
	int	size;
	int	index_value;
	int	marker_value;

	marker = 1;
	size = stack_size(stack, 'a');
	while (size)
	{
		index_value = find_value(stack->a, stack->index_a, index);
		if (index_value <= pivot)
		{
			if (index > 1)
			{
				do_pb(stack);
				display(stack);
				index--;
			}
			marker_value = find_value(stack->a, stack->index_a, marker);
			if (marker_value != index_value)
			{
				swap(stack, index);
				index++;
				size--;
			}
			else
			{
				index++;
				size--;
			}
		}
		else
		{
			index++;
			size--;
		}
	}
}

void	sort_base(t_list *stack)
{
	int	pivot;
	int	marker;
	int	index;

	index = 1;
	marker = 0;
	while (!is_sort(stack))
	{
		pivot = last_num(stack->a);
		quick_sort(stack, pivot, marker, index);
		printf(">>finish range<<\n");
	}
	exit(0);
}

void	sort(t_list *stack)
{
	display(stack);


	while (!is_sort(stack) && !empty_b(stack))
	{
		sort_base(stack);
		exit(0);
		//pull_back();
	}
}
