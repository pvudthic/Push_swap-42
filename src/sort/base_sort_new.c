#include "push_swap.h"

static void	set_sorted(t_list *stack, int size)
{
	t_stack	*stack_a;

	stack_a = stack->a;
	while (size)
	{
		stack_a->range = 0;
		stack_a->sort = 1;
		stack_a->position = 1;
		stack_a = stack_a->next;
		size--;
	}
}

static void	move_to_top_a(t_list *stack, int size, int position)
{
	if (position == 2)
	{
		while (size--)
			do_pa(stack);
	}
	else if (position == 3)
	{
		while (size--)
			do_rra(stack);
	}
	else if (position == 4)
	{
		while (size--)
		{
			do_rrb(stack);
			do_pa(stack);
		}
		/* Debugger */
		// if (stack->size_a == 500 && stack->size_b == 0)
		// {
		// 	printf("here");
		// 	exit(0);
		// }
		/*         */
	}
}

void	base_sort_new(t_list *stack, int size, int position)
{
	if (size == 0)
		return ;
	if (size == 1)
		move_to_top_a(stack, size, position);
	else if (size == 2)
	{
		move_to_top_a(stack, size, position);
		compare_swap(stack, 1);
	}
	else
	{
		if (position == 1)
			sort3_position_1(stack);
		else if (position == 2)
			sort3_position_2(stack);
		else if (position == 3)
			sort3_position_3(stack);
		else
			sort3_position_4(stack);
	}
	//checker(stack);
	set_sorted(stack, size);
}
