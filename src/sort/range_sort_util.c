#include "push_swap.h"
#include "stack.h"
#include "sort.h"

void	checker(t_list *stack)
{
	if (is_sort(stack, 'a'))
	printf("all sorted!\n");
	else
	{
		printf("KO");
		display(stack);
		exit(0);
	}
}

bool	is_sort(t_list *ref, char name)
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
				printf("%d > %d\n", current->nb, current->next->nb);
				return (false);
			}
		}
		else if (name == 'b')
		{
			if ((current->nb < current->next->nb))
				return (false);
		}
		printf("xx  ");
		current = current->next;
	}
	// If the loop completes without returning false, the stack is sorted.
	return (true);
}

// char	find_stack_name(t_list *ref, int max_range)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	stack_a = ref->a;
// 	stack_b = ref->b;
// 	while (stack_a)
// 	{
// 		if (stack_a->range == max_range)
// 			return ('a');
// 		stack_a = stack_a->next;
// 	}
// 	while (stack_b)
// 	{
// 		if (stack_b->range == max_range)
// 			return ('b');
// 		stack_b = stack_b->next;
// 	}
// 	return ('n');
// }
