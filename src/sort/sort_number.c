#include "../../push_swap.h"

/*	This function should partition up & down form pivot index
	Partition up
		pivot = pivot - 1;
	Partion down
		start = pivot + 1;
		pivot = nearest sorted || edge
*/
void	partition(t_list *stack, int pivot)
{
	(void) stack;
	(void) pivot;
}

void	swap(t_list *stack, int target, int marker)
{
	int	lenght;
	int	c_stack_size; // current stack size

	lenght = target - marker;
	if (lenght == 1)
	{
		do_sa(stack);
		printf("do closed swap\n");
		return ;
	}
	c_stack_size = stack->size_a;
	printf("%d\n", c_stack_size);
	if (target > c_stack_size / 2)
		down_swap(stack, target, marker);
	else
		up_swap(stack, target, marker);
}

int	go_sort(t_list *stack, int start, int stop, int size)
{
	int	x;
	int	y;
	int	marker;
	int	pivot;

	if (start == 0)
		start = 1;
	marker = 0;
	pivot = find_value(stack, stop);
	while (size)
	{
		x = find_value(stack, start);
		if (x <= pivot)
		{
			if (marker != 0)
				do_pb(stack);
			marker++;
			y = find_value(stack, marker);
			printf("i_x: %d value_x: %d, i_y: %d value_y: %d\n", start, x, marker, y);
			if (x != y)
				swap(stack, start, marker);
		}
		printf("pass\n");
		start++;
		size--;
	}
	return (stop);
}

/*	recieve (stack, index_start, index_pivot)
	Pusedo code
		to_the_top(stack, index_start);
		find_size(stack, index_start, index_pivot);
		if (size == 0) -> start and pivot is same number so that sorted
			return ;
		new_index_pivot = go_sort(stack, index_start, index_pivot);
		partition(stack, new_pivot);
*/
void	quick_sort(t_list *stack, int start, int pivot)
{
	int		size;
	t_index *tmp;

	to_the_top_a(stack, start);
	size = pivot - start;
	if (size == 0)
		return ;
	pivot = go_sort(stack, start, pivot, size);
	display_stack(stack);
	tmp = stack_start_index(stack->index_a, stack_size(stack, 'a'), stack->index_size);
	start = tmp->index;
	size = pivot - start;
	if (size == 0)
		return ;
	pivot = go_sort(stack, start, pivot, size);
}

/*
	This is sort function that
		send the start index
		and send pivot index
	to the quick sort function
*/
void	sort(t_list *stack)
{
	int	start;
	int	pivot;

	start = stack->index_a->index;
	/*skip first index*/
	pivot = find_index(stack->index_a->next, stack->a, last_num(stack->a));
	quick_sort(stack, start, pivot);
}
