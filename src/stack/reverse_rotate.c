#include "../../push_swap.h"
/*
	Reverse Rotate StackA
	last node become the first node
	(shift the stack up)
*/
void	do_rra(t_list *stack)
{
	t_stack *prev;
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
	stack->a = current;
	printf("rra\n");
}

void	do_rrb(t_list *stack)
{
	t_stack *prev;
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
	stack->b = current;
	printf("rrb\n");
}

void	do_rrr(t_list *stack)
{
	do_rra(stack);
	do_rrb(stack);
	printf("rrr\n");
}
