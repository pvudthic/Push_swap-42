#include "../../push_swap.h"

void	down_swap(t_list *stack, int target, int marker)
{
	int	n_rotate;
	int	temp;

	(void) marker;
	n_rotate = stack->index_size - target;
	temp = n_rotate;
	while (temp)
	{
		do_rra(stack);
		do_pa(stack);
		temp--;
	}
	do_rra(stack);
	do_sa(stack);
	do_ra(stack);
	temp = n_rotate;
	while (temp)
	{
		do_pb(stack);
		do_ra(stack);
		temp--;
	}
}

void	up_swap(t_list *stack, int target, int marker)
{
	int	n_rotate;
	int	temp;

	(void) marker;
	n_rotate = stack->index_size - target;
	temp = n_rotate;
	while (temp)
	{
		do_rra(stack);
		do_pa(stack);
		temp--;
	}
	do_rra(stack);
	do_sa(stack);
	do_ra(stack);
	temp = n_rotate;
	while (temp)
	{
		do_pb(stack);
		do_ra(stack);
		temp--;
	}
}
