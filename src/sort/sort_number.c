#include "../../push_swap.h"

void	sort(t_list *stack)
{
	display(stack);
	do_pb(stack);
	display(stack);
	do_pb(stack);
	display(stack);
	do_pb(stack);
	display(stack);
	do_pa(stack);
	display(stack);
	do_pa(stack);
	display(stack);
	do_sa(stack);
	display(stack);
	/*
	while (is_sort() && empty_b())
		sort_base();
		pull_back();
	*/
}
