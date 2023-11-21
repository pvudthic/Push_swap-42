#include "push_swap.h"

void	get_merge_num(t_list *stack)
{
	if (stack->a)
	{
		stack->pos_1 = stack->a->nb;
		stack->pos_2 = last_num(stack->a);
	}
	if (stack->b)
	{
		stack->pos_4 = last_num(stack->b);
	}
}

int	compare_merge_b(t_list *stack)
{
	if (stack->pos_1 >= stack->pos_2 && stack->pos_1 >= stack->pos_4)
	{
		return (1);
	}
	else if (stack->pos_2 >= stack->pos_1 && stack->pos_2 >= stack->pos_4)
	{
		/*check if stack have 1 number*/
		if (stack->pos_1 == stack->pos_2)
			return (1);
		return (2);
	}
	else
	{
		return (3);
	}
}

void	merge_top_b(t_list *stack)
{
	get_merge_num(stack);
}
