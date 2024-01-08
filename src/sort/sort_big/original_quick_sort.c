#include "sort.h"

static void	partition(t_list *stack, t_stack *stack_tmp, t_stack *marker)
{
	int	prev;
	int	next;
	int	start;

	prev = find_prev(stack_tmp, marker);
	next = find_next(marker);
	start = find_start(stack->tmp, prev);
	easy_sort(stack, start, prev);
	easy_sort(stack, next, find_pivot(stack->tmp, next));
}

t_stack	*tmp_swap(t_list *stack, t_stack *index, t_stack *marker, int start)
{
	int	tmp_swap;

	if (!marker)
		marker = shift_start(stack->tmp, start);
	else
		marker = marker->next;
	if (index->nb != marker->nb)
	{
		tmp_swap = index->nb;
		index->nb = marker->nb;
		marker->nb = tmp_swap;
	}
	return (marker);
}

void	easy_sort(t_list *stack, int start, int pivot)
{
	t_stack	*index;
	t_stack	*marker;
	int		size;

	index = shift_start(stack->tmp, start);
	size = find_sort_size(stack->tmp, start, pivot);
	if (size == 1)
	{
		index->sort = 1;
		return ;
	}
	marker = NULL;
	while (size)
	{
		if (index->nb <= pivot)
			marker = tmp_swap(stack, index, marker, start);
		if (index->next)
			index = index->next;
		size--;
	}
	if (marker)
		marker->sort = 1;
	partition(stack, stack->tmp, marker);
}
