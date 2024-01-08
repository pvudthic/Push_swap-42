#include "instruction.h"

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
	stack->bottom_a = current->next;
	stack->a->next = NULL;
	stack->a = head;
	if (show_output("ra\n", stack->show_output) == -1)
		error_exit(stack);
	stack->top_a = head;
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
	stack->bottom_b = current->next;
	stack->b->next = NULL;
	stack->b = head;
	if (show_output("rb\n", stack->show_output) == -1)
		error_exit(stack);
	stack->top_b = head;
}

static void	ra(t_list *stack)
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
	stack->bottom_a = current->next;
	stack->a->next = NULL;
	stack->a = head;
	stack->top_a = head;
}

static void	rb(t_list *stack)
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
	stack->bottom_b = current->next;
	stack->b->next = NULL;
	stack->b = head;
	stack->top_b = head;
}

void	do_rr(t_list *stack)
{
	ra(stack);
	rb(stack);
	if (show_output("rr\n", stack->show_output) == -1)
		error_exit(stack);
}
