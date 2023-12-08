#include "stack.h"
#include "push_swap.h"

void	do_ra(t_list *stack)
{
	t_stack	*current;
	t_stack	*head;

//	static int i = 0;

	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	head = stack->a->next;
	current = stack->a;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = stack->a;
	stack->bottom_a = current->next; /*adjust position*/
	stack->a->next = NULL;
	stack->a = head;
	printf("ra\n");
	// i++;
	// if (i >= 300)
	// {
	// 	display(stack);
	// 	exit(0);
	// }
	stack->top_a = head; /*adjust position*/
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
	stack->bottom_b = current->next; /*adjust position*/
	stack->b->next = NULL;
	stack->b = head;
	printf("rb\n");
	stack->top_b = head; /*adjust position*/
}

void	do_rr(t_list *stack)
{
	do_ra(stack);
	do_rb(stack);
	printf("rr\n");
}
