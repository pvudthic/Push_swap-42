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

/*
	This is a simple function that
		recieve number in stack
		then
		find return that index
*/
int		find_index(t_index *index, t_stack *stack, int nb)
{
	t_index	*c_index;
	t_stack	*c_stack;

	c_index = index;
	c_stack = stack;
	while (c_stack)
	{
		if (c_stack->nb == nb)
			break;
		c_stack = c_stack->next;
		c_index = c_index->next;
	}
	return (c_index->index);
}

/*
	if start is first index or edges index
	-> do nothing
	else
	-> do push to B
*/
void	to_the_top_a(t_list *stack, int start)
{
	int	n;

	if (start == 0 || start == 1)
		return ;
	n = start;
	while (n > 0)
	{
		do_pb(stack);
		n--;
	}
}

int	find_value(t_list *stack, int start)
{
	int		value;
	int		stack_start;
	t_stack *c_stack;
	t_index *c_index;


	stack_start = 0;
	if (start == 0)
		start = 1;
	c_stack = stack->a;
	c_index = stack->index_a;
	/*shift start*/
	while (stack_start < stack->sa_start)
	{
		stack_start++;
		c_index = c_index->next;
	}
	printf("c_index %d\n", c_index->index);
	value = c_stack->nb;
	while (c_index)
	{
		if (c_index->index == start)
			break;
		value = c_stack->nb;
		c_index = c_index->next;
		c_stack = c_stack->next;
	}
	return (value);
}

void	swap(t_list *stack, int target, int marker)
{
	int	lenght;
	int	c_stack_size; // current stack size

	lenght = target - marker;
	if (lenght == 1)
	{
		printf("->>>>> Here <<<<<-");
		do_sa(stack);
		do_pb(stack);
		return ;
	}
	exit(0);
	c_stack_size = stack_size(stack, 'a');
	printf("%d\n", c_stack_size);
	//if (target > c_stack_size / 2)
		//down_swap(stack, target, marker);
	//else
		//up_swap(stack, target, marker);
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
	printf("pv value :%d\n\n", pivot);
	stack->sa_start++;
	while (size)
	{
		x = find_value(stack, start);
		if (x <= pivot)
		{
			if (marker != 0)
				do_pb(stack);
			printf("stack start: %d\n", stack->sa_start);
			marker++;
			y = find_value(stack, marker);
			printf("i_x: %d, i_y: %d\n", start, marker);
			printf("do swap(value_x: %d, value_y: %d)\n", x, y);
			if (x > y)
			{
				swap(stack, start, marker);
			}
		}
		printf("pass\n");
		if (marker == 1)
			stack->sa_start--;
		start++;
		size--;
	}
	return (0);
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
	int	size;
	printf("st. index: %d , pivot index: %d\n", start, pivot);

	to_the_top_a(stack, start);
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
	/*initialize stack start to index 1*/
	stack->sa_start = 0;
	/*skip first index*/
	pivot = find_index(stack->index_a->next, stack->a, last_num(stack->a));
	quick_sort(stack, start, pivot);
}
