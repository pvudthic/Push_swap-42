#include "stack.h"
/*
	Reverse Rotate StackA
	last node become the first node
	(shift the stack up)
*/
void	do_rra(t_list *stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	current = stack->a;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = stack->a;
	prev->next = NULL;
	stack->bottom_a = prev; /*adjust position*/
	stack->a = current;
	stack->top_a = stack->a; /*adjust position*/
	printf("rra\n");
}

void	do_rrb(t_list *stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	current = stack->b;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = stack->b;
	prev->next = NULL;
	stack->bottom_b = prev; /*adjust position*/
	stack->b = current;
	stack->top_b = stack->b; /*adjust position*/
	printf("rrb\n");
}

void	do_rrr(t_list *stack)
{
	do_rra(stack);
	do_rrb(stack);
	printf("rrr\n");
}
