#include "stack.h"

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
		/* Handling Information*/
		stack->top_a = stack->a; /*adjust position*/
		stack->top_b = stack->b; /*adjust position*/
		stack->size_a += 1; /*adjust size*/
		stack->size_b -= 1; /*adjust size*/
		if (stack->size_a == 2)
			stack->bottom_a = stack->a->next;
		else if (stack->size_a == 1)
			stack->bottom_a = stack->a;
		if (stack->size_b <= 1)
			stack->bottom_b = stack->b;
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
		/* Handling Information*/
		stack->top_a = stack->a; /*adjust position*/
		stack->top_b = stack->b; /*adjust position*/
		stack->size_a -= 1; /*adjust size*/
		stack->size_b += 1; /*adjust size*/
		if (stack->size_b == 2)
			stack->bottom_b = stack->b->next;
		else if (stack->size_b == 1)
			stack->bottom_b = stack->b;
		if (stack->size_a <= 1)
			stack->bottom_a = stack->a;
	}
	else
		return ;
}
