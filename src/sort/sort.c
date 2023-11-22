#include "../../push_swap.h"

void	easy_swap(t_list *stack, int start)
{
	int	i;

	i = start;
	while (i - 1 > 0)
	{
		do_pb(stack);
		i--;
	}
	do_sa(stack);
	i = start;
	while (i - 1 > 0)
	{
		do_pa(stack);
		i--;
	}
}

void	length_swap(t_list *stack, int start, int stop)
{
	int	i;

	i = start;
	while (i > 0)
	{
		do_pb(stack);
		do_rb(stack);
		i--;
	}
	i = stop;
	while (i > 0)
	{
		do_pb(stack);
		i--;
	}
	do_rrb(stack);
	do_pa(stack);
	do_rb(stack);
	i = stop - 1;
	while (i > 0)
	{
		do_pa(stack);
		i--;
	}
	i = start;
	while (i > 0)
	{
		do_rrb(stack);
		do_pa(stack);
		i--;
	}
}
