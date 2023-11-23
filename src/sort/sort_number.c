#include "../../push_swap.h"

/*
	This is a simple function that
		recieve number in stack
		then
		find return that index
*/
int		find_index(t_index *index,t_stack *stack, int nb)
{
	t_index	*c_index;
	t_stack	*c_stack;

	printf("find number : %d\n", nb);
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

void	quick_sort(t_list *stack, int start, int pivot)
{
	printf("st: %d , p: %d\n", start, pivot);

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
