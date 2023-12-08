#include "push_swap.h"

void	find_rank(t_stack *stack_a, t_stack *stack_tmp)
{
	int		rank;
	t_stack *current_tmp;

	current_tmp = stack_tmp;
	rank = 1;
	while (current_tmp)
	{
		if (current_tmp->nb == stack_a->nb)
		{
			stack_a->nb = rank;
			return ;
		}
		current_tmp = current_tmp->next;
		rank++;
	}
}

void	create_rank(t_list *stack)
{
	t_stack	*stack_a;
	t_stack	*stack_tmp;
	int		pivot;
	int		start;

	pivot = find_pivot(stack->tmp, stack->tmp->nb);
	start = find_start(stack->tmp, pivot);
	easy_sort(stack, start, pivot);
	stack_a = stack->a;
	stack_tmp = stack->tmp;
	while (stack_a)
	{
		find_rank(stack_a, stack_tmp);
		stack_a = stack_a->next;
	}
}
