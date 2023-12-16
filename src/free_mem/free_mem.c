#include "libft.h"
#include "free_mem.h"
#include "stack.h"

#include "push_swap.h"

void	error_exit(t_list *stack)
{

	if (stack)
		free_stack_ab(stack);
	write(2, "Error\n", 6);
	exit(1);
}

static void	free_stack_tmp(t_list *stack)
{
	t_stack	*backup;

	if (stack->tmp)
	{
		while (stack->tmp)
		{
			backup = stack->tmp;
			stack->tmp = stack->tmp->next;
			free(backup);
		}
	}
}

void	free_stack_ab(t_list *stack)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (stack->a)
	{
		while (stack->a)
		{
			tmp_a = stack->a;
			stack->a = stack->a->next;
			free(tmp_a);
		}
	}
	if (stack->b)
	{
		while (stack->b)
		{
			tmp_b = stack->b;
			stack->b = stack->b->next;
			free(tmp_b);
		}
	}
	free_stack_tmp(stack);
	free(stack);
}
