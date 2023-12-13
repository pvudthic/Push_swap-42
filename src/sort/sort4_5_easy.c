#include "sort.h"

void	sort4_5_easy(t_list *stack)
{
	int size;
	int	pivot;

	create_rank(stack);
	size = stack->size_a;
	if (size == 5) // choose apropiately pivot
		pivot = 2;
	else
		pivot = 1;
	while (size--) // move number
	{
		if (stack->top_a->nb > pivot)
			do_ra(stack);
		else
			do_pb(stack);
	}
	sort3_easy(stack);
	if (stack->size_b > 1) // sort b if size == 5
		compare_swap(stack, 2);
	size = stack->size_b;
	while (size--) // move number back
		do_pa(stack);
	//display(stack);
}
