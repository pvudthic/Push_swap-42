#include "push_swap.h"

void	display_stack(t_s *stack)
{
	while (stack->a)
	{
		printf("sa: %d\n", stack->a->nb);
		stack->a = stack->a->next;
	}
	while (stack->b)
	{
		printf("sb: %d\n", stack->b->nb);
		stack->b = stack->b->next;
	}
}

void	check_duplicate(int nb, t_sa *stack_a, t_s *stack)
{
	t_sa	*head_stack;

	head_stack = stack_a;
	while (head_stack)
	{
		if (nb == head_stack->nb)
		{
			printf("number is duplicate\n");
			error_exit(stack);
		}
		head_stack = head_stack->next;
	}
}

void	free_stack_ab(t_s *stack)
{
	t_sa	*tmp_a;
	t_sb	*tmp_b;

	printf("free Stack\n");
	if (stack->a)
	{
		printf("freeing.. A\n");
		while (stack->a)
		{
			tmp_a = stack->a;
			stack->a = stack->a->next;
			free(tmp_a);
		}
	}
	if (stack->b)
	{
		printf("freeing.. B\n");
		while (stack->b)
		{
			tmp_b = stack->b;
			stack->b = stack->b->next;
			free(tmp_b);
		}
	}
	free(stack);
}

void	error_exit(t_s *stack)
{
	if (stack)
	{
		free_stack_ab(stack);
	}
	printf("Error\n");
	exit(0);
}
