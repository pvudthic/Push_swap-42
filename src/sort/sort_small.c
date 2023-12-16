#include "sort.h"
#include "move.h"

void	sort4_5_easy(t_list *stack)
{
	int	size;
	int	pivot;

	create_rank(stack);
	size = stack->size_a;
	if (size == 5)
		pivot = 2;
	else
		pivot = 1;
	while (size--)
	{
		if (stack->top_a->nb > pivot)
			do_ra(stack);
		else
			do_pb(stack);
	}
	sort3_easy(stack);
	if (stack->size_b > 1)
		compare_swap(stack, 2);
	size = stack->size_b;
	while (size--)
		do_pa(stack);
}

void	sort3_easy(t_list *stack)
{
	int	top;
	int	mid;
	int	bot;

	stack->n_1 = stack->a->nb;
	stack->n_2 = stack->a->next->nb;
	stack->n_3 = stack->a->next->next->nb;
	assign_lane(stack, &top, &mid, &bot);
	if (top == 2 && mid == 1 && bot == 3)
		do_sa(stack);
	else if (top == 3 && mid == 2 && bot == 1)
	{
		do_sa(stack);
		do_rra(stack);
	}
	else if (top == 3 && mid == 1 && bot == 2)
		do_ra(stack);
	else if (top == 1 && mid == 3 && bot == 2)
	{
		do_sa(stack);
		do_ra(stack);
	}
	else if (top == 2 && mid == 3 && bot == 1)
		do_rra(stack);
}
