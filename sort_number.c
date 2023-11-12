#include "push_swap.h"

void	sort(t_list *stack)
{
	do_pb(stack);
	do_sa(stack);
	do_pb(stack);
	do_pb(stack);
	do_sa(stack);
	do_pa(stack);
	display_stack(stack);
	return ;
}
