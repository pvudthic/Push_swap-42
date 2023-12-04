#include "push_swap.h"

int		find_next(t_stack *marker)
{
	//Next number
	if (marker->next)
	{
		marker = marker->next;
		return (marker->nb);
	}
	return marker->nb;
}

int		find_prev(t_stack *ref, t_stack *marker)
{
	t_stack *stack_tmp;

	stack_tmp = ref;
	/*first doesn't have prev*/
	if (stack_tmp == marker)
		return (stack_tmp->nb);
	while (stack_tmp)
	{
		if (stack_tmp->next == marker)
			return (stack_tmp->nb);
		stack_tmp = stack_tmp->next;
	}
	return (stack_tmp->nb);
}

void	partition(t_list *stack, t_stack *stack_tmp, t_stack *marker)
{
	int	prev;
	int	next;
	int	start;

	prev = find_prev(stack_tmp, marker);
	next = find_next(marker);
	//printf("prev:next %d:%d\n", prev, next);
	start = find_start(stack->tmp, prev);
	easy_sort(stack, start, prev);
	easy_sort(stack, next, find_pivot(stack->tmp, next));
	//display_tmp(stack);
}

void	tmp_swap(t_stack *index, t_stack *marker)
{
	int	tmp_swap;

	//printf("swap %d:%d\n", index->nb, marker->nb);
	tmp_swap = index->nb;
	index->nb = marker->nb;
	marker->nb = tmp_swap;
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
		index->true_pos = 1;
		return ;
	}
	//printf("start:%d , pivot:%d || size = %d\n", start, pivot, size);
	//display_tmp(stack);
	marker = NULL;
	while (size)
	{
		if (index->nb <= pivot)
		{
			if (!marker)
				marker = shift_start(stack->tmp, start);
			else
				marker = marker->next;
			if (index->nb != marker->nb)
			{
				//printf("swap: %d:%d\n", index->nb, marker->nb);
				tmp_swap(index, marker);
				//display_tmp(stack);
			}
		}
		if (index->next)
			index = index->next;
		size--;
	}
	if (marker)
		marker->true_pos = 1;
	//printf("<<<<<<finish rank<<<<<<\n");
	partition(stack, stack->tmp, marker);
}
