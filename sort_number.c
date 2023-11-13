#include "push_swap.h"

void	sort(t_list *stack)
{
	do_pb(stack);
	display_stack(stack);
	do_ra(stack);
	display_stack(stack);
	do_rra(stack);
	display_stack(stack);
	return ;
}
