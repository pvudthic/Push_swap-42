#include "../../push_swap.h"

/*
	Rotate StackA
	first node become the last node
	(shift the stack down)
*/
void	do_ra(t_list *stack)
{
	t_stack	*current;
	t_stack	*head;

	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	head = stack->a->next;
	current = stack->a;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = stack->a;
	stack->a->next = NULL;
	stack->a = head;
	printf("ra\n");
}

void	do_rb(t_list *stack)
{
	t_stack	*head;
	t_stack	*current;

	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	head = stack->b->next;
	current = stack->b;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = stack->b;
	stack->b->next = NULL;
	stack->b = head;
	printf("rb\n");
}
/*
	Rotate StackA & Rotate Stack B
	first node become the last node
	(shift the stack down)
*/
void	do_rr(t_list *stack)
{
	do_ra(stack);
	do_rb(stack);
	printf("rr\n");
}
