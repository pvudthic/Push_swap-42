#include "sort.h"

static void	case_top_1(t_list *stack)
{
	do_rb(stack);
	do_pa(stack);
	do_pa(stack);
	compare_swap(stack, 1);
	do_rrb(stack);
	do_pa(stack);
}

static void	case_top_2(t_list *stack, int mid)
{
	if (mid == 3)
	{
		do_sb(stack);
		do_pa(stack);
		do_pa(stack);
		do_pa(stack);
	}
	else
	{
		do_rb(stack);
		do_sb(stack);
		do_pa(stack);
		do_rrb(stack);
		do_pa(stack);
		do_pa(stack);
	}
}

static void	case_top_3(t_list *stack)
{
	do_pa(stack);
	do_pa(stack);
	do_pa(stack);
	compare_swap(stack, 1);
}

void	sort3_position_2(t_list *stack)
{
	int	top;
	int	mid;
	int	bot;

	stack->n_1 = stack->range_stack->nb;
	stack->n_2 = stack->range_stack->next->nb;
	stack->n_3 = stack->range_stack->next->next->nb;
	assign_lane(stack, &top, &mid, &bot);
	if (top == 3)
		case_top_3(stack);
	else if (top == 1)
		case_top_1(stack);
	else
		case_top_2(stack, mid);
}
