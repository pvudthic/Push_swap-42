#include "../../push_swap.h"

#include <stdio.h>
#include <unistd.h>

static t_index *shift_index(t_index *index)
{
	if (!index)
		return (NULL);
	else
		index = index->next;
	return index;
}

static t_stack *shift_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	else
		stack = stack->next;
	return stack;
}

t_stack	*display_stack(t_stack *stack, t_index *index, int start)
{
	if (stack != NULL && index->index >= start)
	{
		printf("| [%d]", index->index);
		printf("	 %d	  |", stack->nb);
		return (shift_stack(stack));
	}
	else
	{
		printf("| [%d]", index->index);
		printf("	          |");
		return (stack);
	}
}

void	clear_screen(void)
{
	sleep(2);
	printf("\033[H\033[J");
}

void	display(t_list *stack)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_index *i_a;
	t_index *i_b;

	stack_a = stack->a;
	stack_b = stack->b;
	i_a = stack->index_a;
	i_b = stack->index_b;
	printf("|------  A  ------|   ");
	printf("|-------  B  -------|\n");
	printf("| i      n        |   ");
	printf("| i       n         |\n");
	printf("|-----------------|   |-------------------|\n");
	printf("| [0]	          |   | [0]	          |\n");
	i_a = shift_index(i_a);
	i_b = shift_index(i_b);
	while (i_a)
	{
		stack_a = display_stack(stack_a, i_a, stack->start_i_a);
		printf("   ");
		stack_b = display_stack(stack_b, i_b, stack->start_i_b);
		printf("\n");
		i_a = shift_index(i_a);
		i_b = shift_index(i_b);
	}
	printf("|-----------------|   |-------------------|\n");
}
