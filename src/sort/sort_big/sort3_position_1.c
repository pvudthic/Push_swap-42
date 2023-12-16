#include "sort.h"
#include "move.h"

static void	case_top_1(t_list *stack, int mid)
{
	if (mid == 2)
		return ;
	else
	{
		do_pb(stack);
		do_sa(stack);
		do_pa(stack);
	}
}

static void	case_top_2(t_list *stack, int mid)
{
	if (mid == 1)
		do_sa(stack);
	else
	{
		do_pb(stack);
		do_sa(stack);
		do_ra(stack);
		do_pa(stack);
		do_rra(stack);
	}
}

static void	case_top_3(t_list *stack, int bot)
{
	do_sa(stack);
	do_ra(stack);
	do_sa(stack);
	if (bot == 2)
		do_rra(stack);
	else
	{
		do_pb(stack);
		do_rra(stack);
		do_pa(stack);
	}
}

void	sort3_position_1(t_list *stack)
{
	int	top;
	int	mid;
	int	bot;

	stack->n_1 = stack->range_stack->nb;
	stack->n_2 = stack->range_stack->next->nb;
	stack->n_3 = stack->range_stack->next->next->nb;
	assign_lane(stack, &top, &mid, &bot);
	if (top == 1)
		case_top_1(stack, mid);
	else if (top == 2)
		case_top_2(stack, mid);
	else
		case_top_3(stack, bot);
}
