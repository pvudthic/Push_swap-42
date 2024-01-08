#include "debugger.h"

static t_stack	*shift_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	else
		stack = stack->next;
	return (stack);
}

static t_stack	*display_stack(t_stack *stack, int index)
{
	if (stack != NULL)
	{
		printf("| [%4d]	", index);
		printf("%6d		< %d >   %d  [%d] |", stack->nb, stack->range, stack->position ,stack->sort);
		return (shift_stack(stack));
	}
	else
	{
		printf("| [%4d]   ", index);
		printf("%6s		<   >      [ ] |", " ");
		return (stack);
	}
}

void	display(t_list *stack)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = stack->a;
	stack_b = stack->b;
	i = 1;
	printf("|----------------------  A  -------------------|   ");
	printf("|-------------------  B  -------------------|\n");
	printf("|	i	    n		[ R ]  [P] [S] |   ");
	printf("|	i	    n		[ R ]  [P] [S] |\n");
	printf("|----------------------------------------------|   |-------------------------------------------|\n");
	while (i <= stack->t_size)
	{
		stack_a = display_stack(stack_a, i);
		printf("   ");
		stack_b = display_stack(stack_b, i);
		printf("\n");
		i++;
	}
	printf("|----------------------------------------------|   |-------------------------------------------|\n");
}

// void	display_tmp(t_list *stack)
// {
// 	t_stack	*stack_tmp;
// 	t_index	*i_tmp;

// 	stack_tmp = stack->tmp;
// 	i_tmp = stack->index;
// 	printf("|----------------------  T  -------------------|\n");
// 	printf("|	i	    n		[ R ]  [P] [S] |\n");
// 	printf("|----------------------------------------------|\n");
// 	while (i_tmp)
// 	{
// 		stack_tmp = display_stack(stack_tmp, i_tmp);
// 		printf("\n");
// 		i_tmp = shift_index(i_tmp);
// 	}
// 	printf("|----------------------------------------------|\n");
// }


bool	is_sort_name(t_list *ref, char name)
{
	t_stack *current;

	if (name == 'a')
		current = ref->a;
	else
		current = ref->b;
	while (current->next != NULL)
	{
		if (name == 'a')
		{
			if ((current->nb > current->next->nb) && current->range == 0 && current->next->range == 0)
			{
				//printf("%d > %d\n", current->nb, current->next->nb);
				return (false);
			}
		}
		else if (name == 'b')
		{
			if ((current->nb < current->next->nb))
				return (false);
		}
		//printf("xx  ");
		current = current->next;
	}
	// If the loop completes without returning false, the stack is sorted.
	return (true);
}

void	checker(t_list *stack)
{
	if (is_sort_name(stack, 'a'))
		printf("all sorted!\n");
	else
	{
		printf("KO");
		display(stack);
		exit(0);
	}
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
