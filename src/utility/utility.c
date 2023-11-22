#include "../../push_swap.h"

void	check_duplicate(int nb, t_stack *stack_a, t_list *stack)
{
	t_stack	*head_stack;

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

void	free_stack_ab(t_list *stack)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

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

void	error_exit(t_list *stack)
{
	if (stack)
	{
		free_stack_ab(stack);
	}
	printf("Error\n");
	exit(0);
}
