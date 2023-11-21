#include "push_swap.h"

/*
	compare 2 number
	if top number < bottom on top
		return 0
	other wise
		return 1
*/
int		compare_top(t_stack *stack)
{
	int		prev;
	int		main;
	t_stack	*s_current;

	s_current = stack;
	prev = s_current->nb;
	s_current =s_current->next;
	main = s_current->nb;
	if (prev < main)
		return (0);
	return (1);
}
void	create_pos_2(t_list *stack, int	total, int size)
{
	int	i;
	int	j;

	j = total;
	if (compare_top(stack->a) == 1)
		do_sa(stack);
	display_stack(stack);
	while (j > 0)
	{
		i = 0;
		while (i++ < size)
			do_pb(stack);
		j--;
	}
}

void	create_pos_3(t_list *stack, int	total, int remain)
{
	int	i;
	int	j;

	if ((total * 2) == remain)
		return ;
	j = total;
	while (j > 0)
	{
		if (compare_top(stack->a) == 1)
			do_sa(stack);
		i = 0;
		while (i++ < 2)
			do_ra(stack);
		j--;
	}
}

void	create_pos_4(t_list *stack, int	total, int size)
{
	int	i;
	int	j;

	j = total;
	if (compare_top(stack->a) == 0)
		do_sa(stack);
	while (j > 0)
	{
		i = 0;
		while (i++ < size)
			do_pb(stack);
		j--;
	}
}

int	compare_num(int num1, int num2, int num3)
{
	if (num1 >= num2 && num1 >= num3)
	{
		return (1);
	}
	else if (num2 >= num1 && num2 >= num3)
	{
		return (2);
	}
	else
	{
		return (3);
	}

}

void	merge_top_a(t_list *stack)
{
	int	pos_2;
	int	pos_3;
	int	pos_4;
	int	do_operation;

	pos_2 = last_num(stack->a);
	pos_3 = stack->b->nb;
	pos_4 = last_num(stack->b);
	printf("num 1: %d num 2: %d num 3 : %d\n", pos_2, pos_3, pos_4);
	do_operation = compare_num(pos_2, pos_3, pos_4);
	if (do_operation == 1)
		do_rra(stack);
	else if (do_operation == 2)
		do_pa(stack);
	else if (do_operation == 3)
	{
		do_rrb(stack);
		do_pa(stack);
	}
}

void	merge(t_list *stack, char position)
{
	if (position == '1')
	{
		merge_top_a(stack);
	}
}

void	merge_sort(t_list *stack)
{
	display_stack(stack);
	/*parse chunk in position*/
	create_pos_4(stack, ((stack->size_a) / 2) / 3, 2);
	create_pos_2(stack, ((stack->size_a) / 2) / 3, 2);
	create_pos_3(stack, ((stack->size_a) / 2) / 3, stack_size(stack, 'a'));
	display_stack(stack);
	merge(stack, '1');
}

void	sort(t_list *stack)
{
	stack_size(stack, 'a');
	if (stack->size_a > 5)
		merge_sort(stack);
	else
		tiny_sort(stack);
}
