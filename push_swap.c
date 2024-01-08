#include "stack.h"
#include "sort.h"

static void	init_position(t_list *stack)
{
	stack->top_a = stack->a;
	stack->bottom_a = bottom_stack(stack->a);
	stack->top_b = NULL;
	stack->bottom_b = NULL;
	stack->size_a = stack->t_size;
	stack->size_b = 0;
}

/* Check if is reived number already sort */
static bool	is_sort(t_list *ref)
{
	t_stack	*current;

	current = ref->a;
	while (current->next != NULL)
	{
		if ((current->nb > current->next->nb))
			return (false);
		current = current->next;
	}
	return (true);
}

/* Receive number from argument */
/* Sort number with 2 stack called "A","B" */
int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	if (argc > 1)
	{
		stack = init_stack(argc, argv);
		init_position(stack);
		stack->show_output = 1;
		if (stack)
		{
			if (!is_sort(stack))
			{
				if (stack->size_a <= 5)
					small_sort(stack);
				else
					big_sort(stack);
			}
			clear_data(stack);
		}
	}
}
// Notes
// Do nothing when no input argument (arg count = 1)
