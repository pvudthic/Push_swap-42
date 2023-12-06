#include "push_swap.h"

void	sort_size_3(t_list *stack)
{
	int	n_1;
	int	n_2;
	int	n_3;

	n_1 = stack->a->nb;
	n_2 = stack->a->next->nb;
	n_3 = stack->a->next->next->nb;
	if (n_1 > n_2 && n_2 < n_3)
		do_sa(stack);
	else if (n_1 > n_2 && n_2 > n_3)
	{
		do_sa(stack);
		do_rra(stack);
	}
	else if (n_1 > n_2 && n_1 > n_3)
		do_ra(stack);
	else if (n_1 < n_2 && n_2 > n_3)
	{
		do_sa(stack);
		do_ra(stack);
	}
	else if (n_3 < n_1 && n_2 > n_1)
		do_rra(stack);
}

void	sort_size_4(t_list *stack)
{
	int	r_count;

	r_count = 0;
	do_pb(stack);
	sort_size_3(stack);
	while (1)
	{
		if (stack->a->nb + 1 == stack->b->nb)
		{
			do_ra(stack);
			do_pa(stack);
			r_count++;
			break ;
		}
		do_ra(stack);
		r_count++;
	}
	while (r_count)
	{
		do_rra(stack);
		r_count--;
	}
}

void	sort_size_2(t_list *stack)
{
	int	n_1;
	int	n_2;

	n_1 = stack->a->nb;
	n_2 = stack->a->next->nb;
	if (n_1 < n_2)
		return ;
	else
		do_sa(stack);
}

void	base_sort(t_list *stack, int size)
{
	printf(">>>> sort base by : size =%d\n", size);
	if (size == 1)
		return ;
	else if (size == 2)
		sort_size_2(stack);
	else if (size == 3)
		sort_size_3(stack);
	else if (size == 4)
		sort_size_4(stack);
}
