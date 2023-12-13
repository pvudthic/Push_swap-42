#include "push_swap.h"

// void	set_sorted(t_list *stack, int size)
// {
// 	t_stack	*stack_a;

// 	stack_a = stack->a;
// 	while (size)
// 	{
// 		stack_a->range = 0;
// 		stack_a->sort = 1;
// 		stack_a->position = 1;
// 		stack_a = stack_a->next;
// 		size--;
// 	}
// }

void	sort_size_3(t_list *stack)
{
	int	n_1;
	int	n_2;
	int	n_3;

	n_1 = stack->a->nb;
	n_2 = stack->a->next->nb;
	n_3 = stack->a->next->next->nb;
	/* 2 1 3*/
	if (n_1 > n_2 && n_1 < n_3 && n_2 < n_3)
		do_sa(stack);
	/* 3 2 1*/
	else if (n_1 > n_2 && n_1 > n_3 && n_2 > n_3)
	{
		do_sa(stack);
		if (stack->size_a == 3)
			do_rra(stack);
		else
		{
			do_ra(stack);
			do_sa(stack);
			do_pb(stack);
			do_rra(stack);
			do_pa(stack);
		}

	}
	/* 3 1 2*/
	else if (n_1 > n_2 && n_1 > n_3 && n_2 < n_3)
	{
		if (stack->size_a == 3)
			do_ra(stack);
		else
		{
			do_sa(stack);
			do_ra(stack);
			do_sa(stack);
			do_rra(stack);
		}
	}
	/* 1 3 2*/
	else if (n_1 < n_2 && n_1 < n_3 && n_2 > n_3)
	{
		if (stack->size_a == 3)
		{
			do_sa(stack);
			do_ra(stack);
		}
		else
		{
			do_pb(stack);
			do_sa(stack);
			do_pa(stack);
		}
	}
	/* 2 3 1*/
	else if (n_1 < n_2 && n_1 > n_3 && n_2 > n_3)
	{
		if (stack->size_a == 3)
			do_rra(stack);
		else
		{
			do_pb(stack);
			do_sa(stack);
			do_ra(stack);
			do_pa(stack);
			do_rra(stack);
		}
	}
	//set_sorted(stack, 3);
}

void	sort_size_2(t_list *stack)
{
	int	n_1;
	int	n_2;

	n_1 = stack->a->nb;
	n_2 = stack->a->next->nb;
	if (n_1 > n_2)
		do_sa(stack);
	//set_sorted(stack, 2);
}

void	base_sort(t_list *stack, int size, int position)
{
	int	count;

	count = 0;
	//printf(">>>> sort base by : size = %d\n", size);
	if (position == 2)
	{
		while (count != size)
		{
			do_pa(stack);
			count++;
		}
	}
	else if (position == 4)
	{
		while (count != size)
		{
			do_rrb(stack);
			do_pa(stack);
			count++;
		}
	}
	else if (position == 3)
	{
		while (count != size)
		{
			do_rra(stack);
			count++;
		}
	}
	if (size == 1)
	{
		//set_sorted(stack, 1);
		return ;
	}
	else if (size == 2)
		sort_size_2(stack);
	else if (size == 3)
		sort_size_3(stack);
}
