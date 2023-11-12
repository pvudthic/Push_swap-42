#include "push_swap.h"

void	do_ra(t_list *stack)
{
	t_stack	*head;
	t_stack	*current;

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

void	do_rr(t_list *stack)
{
	do_ra(stack);
	do_rb(stack);
	printf("rr\n");
}

// void	do_rra(t_list *stack)
// {

// }

// void	do_rrb(t_list *stack)
// {

// }

// void	do_rrr(t_list *stack)
// {

// }
