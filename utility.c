#include "push_swap.h"

void	display_stack(s_list *stack)
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

static void	free_stack_AB(s_list *stack)
{
	a_list	*tmp_a;
	b_list	*tmp_b;

	if (stack->a)
	{
		while (stack->a)
		{
			tmp_a = stack->a;
			stack->a = stack->a->next;
			free(tmp_a);
		}
	}
	if (stack->a)
	{
		while (stack->b)
		{
			tmp_b = stack->b;
			stack->b = stack->b->next;
			free(tmp_b);
		}
	}
	free(stack);
}

void	error_exit(s_list *stack)
{
	free_stack_AB(stack);
	printf("Error\n");
	exit(0);
}
