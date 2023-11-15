#include "push_swap.h"

void	do_pa(t_list *stack)
{
	t_stack	*tmp_stack;

	if (stack->b)
	{
		tmp_stack = stack->b;
		stack->b = stack->b->next;
		tmp_stack->next = stack->a;
		stack->a = tmp_stack;
		printf("pa\n");
	}
	else
		return ;
}

void	do_pb(t_list *stack)
{
	t_stack	*tmp_stack;

	if (stack->a)
	{
		tmp_stack = stack->a;
		stack->a = stack->a->next;
		tmp_stack->next = stack->b;
		stack->b = tmp_stack;
		printf("pb\n");
	}
	else
		return ;
}
