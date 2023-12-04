#include "push_swap.h"

void	create_rank(t_list *stack)
{
	int	pivot;
	int	start;

	pivot = find_pivot(stack->tmp, stack->tmp->nb);
	start = find_start(stack->tmp, pivot);
	printf("pv:%d, st:%d\n", pivot, start);
	easy_sort(stack, start, pivot);
	display_tmp(stack);
}

void	sort(t_list *stack)
{
	create_rank(stack);
	// /display(stack);
}
