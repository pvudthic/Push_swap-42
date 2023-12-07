#include "push_swap.h"

#include <stdio.h>
#include <unistd.h>

static t_index	*shift_index(t_index *index)
{
	if (!index)
		return (NULL);
	else
		index = index->next;
	return (index);
}

static t_stack	*shift_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	else
		stack = stack->next;
	return (stack);
}

static t_stack	*display_stack(t_stack *stack, t_index *index, int start)
{
	if (stack != NULL && index->i >= start)
	{
		printf("| [%4d]	", index->i);
		printf("%6d		< %d >   %d  [%d] |", stack->nb, stack->range, stack->position ,stack->sort);
		return (shift_stack(stack));
	}
	else
	{
		printf("| [%4d]   ", index->i);
		printf("%6s			       |", " ");
		return (stack);
	}
}

void	display(t_list *stack)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_index	*i_a;
	t_index	*i_b;

	stack_a = stack->a;
	stack_b = stack->b;
	i_a = stack->index;
	i_b = stack->index;
	printf("|----------------------  A  -------------------|   ");
	printf("|-------------------  B  -------------------|\n");
	printf("|	i	    n		[ R ]  [P] [S] |   ");
	printf("|	i	    n		[ R ]  [P] [S] |\n");
	printf("|----------------------------------------------|   |-------------------------------------------|\n");
	while (i_a)
	{
		stack_a = display_stack(stack_a, i_a, 0);
		printf("   ");
		stack_b = display_stack(stack_b, i_b, 0);
		printf("\n");
		i_a = shift_index(i_a);
		i_b = shift_index(i_b);
	}
	printf("|----------------------------------------------|   |-------------------------------------------|\n");
}

void	display_tmp(t_list *stack)
{
	t_stack	*stack_tmp;
	t_index	*i_tmp;

	stack_tmp = stack->tmp;
	i_tmp = stack->index;
	printf("|----------------------  T  -------------------|\n");
	printf("|	i	    n		[ R ]  [P] [S] |\n");
	printf("|----------------------------------------------|\n");
	while (i_tmp)
	{
		stack_tmp = display_stack(stack_tmp, i_tmp, 0);
		printf("\n");
		i_tmp = shift_index(i_tmp);
	}
	printf("|----------------------------------------------|\n");
}

void	display_position(t_list *stack)
{
	printf("\n\n|---------[ T_A ]----------|--------[ T_B ]---------|\n");
	printf("|%25s | %23s|\n", " ", " ");
	if (stack->top_a)
		printf("| %10p   [%7d]", stack->top_a, stack->top_a->nb);
	else if (!stack->top_a)
		printf("| %10p   %10s", stack->top_a, " ");
	if (stack->top_b)
		printf("  | %10p   [%7d]|\n", stack->top_b, stack->top_b->nb);
	else if (!stack->top_b)
		printf("  | %10p   %10s|\n", stack->top_b, " ");
	printf("|%25s | %23s|\n", " ", " ");
	printf("|---------------------------------------------------|\n");
	printf("|%25s | %23s|\n", " ", " ");
	if (stack->bottom_a)
		printf("| %10p   [%7d]", stack->bottom_a, stack->bottom_a->nb);
	else if (!stack->bottom_a)
		printf("| %10p   %10s", stack->bottom_a, " ");
	if (stack->bottom_b)
		printf("  | %10p   [%7d]|\n", stack->bottom_b, stack->bottom_b->nb);
	else if (!stack->bottom_b)
		printf("  | %10p   %10s|\n", stack->bottom_b, " ");
	printf("|%25s | %23s|\n", " ", " ");
	printf("|---------[ B_A ]----------|---------[ B_B ]--------|\n");
	printf("|---------{ %3d }----------|---------{ %3d }--------|\n", stack->size_a, stack->size_b);
}
