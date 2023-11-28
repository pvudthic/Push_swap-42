#include "../../push_swap.h"

int		find_value(t_stack *stack, t_index *index, int target_index)
{
	t_index *c_index;
	t_stack *c_stack;
	int		n;

	if (target_index == 0)
		target_index = 1;
	n = 1;
	c_index = index->next;
	c_stack = stack;
	while (n != target_index)
	{
		c_index = c_index->next;
		c_stack = c_stack->next;
		n++;
	}
	return c_stack->nb;
}

void	to_top_a(t_list *stack, int marker)
{
	if (marker > 1)
	{
		do_pb(stack);
		//display(stack);
	}
}

void	bottom_swap(t_list *stack, int target, int size)
{
	int	n;

	n = 0;
	//printf("bottom swap\n");
	while (n < (size - target))
	{
		do_rra(stack);
		do_pb(stack);
		n++;
	}
	do_rra(stack);
	do_sa(stack);
	do_ra(stack);
	n = 0;
	while (n < (size - target))
	{
		do_pa(stack);
		do_ra(stack);
		n++;
	}
}

void	top_swap(t_list *stack, int target, int size)
{
	int	n;

	n = 0;
	(void)size;
	//printf("top swap\n");
	do_pb(stack);
	while (n < target - 2)
	{
		do_ra(stack);
		n++;
	}
	do_pa(stack);
	do_sa(stack);
	do_pb(stack);
	n = 0;
	while (n < target - 2)
	{
		do_rra(stack);
		n++;
	}
	do_pa(stack);
}

void	swap(t_list *stack, int target)
{
	int	size;

	//display(stack);
	size = stack_size(stack, 'a');
	if (target == 2)
		do_sa(stack);
	else if (target > (size / 2))
	{
		bottom_swap(stack, target, size);
	}
	else if (target <= (size / 2))
	{
		top_swap(stack, target, size);
	}
	//display(stack);
}

void	quick_sort(t_list *stack, int pivot, int marker, int index)
{
	int	size;
	int	index_value;
	int	marker_value;
	int	flag;

	flag = 0;
	marker = 1;
	size = stack_size(stack, 'a');
	while (size)
	{
		index_value = find_value(stack->a, stack->index_a, index);
		//printf("index_value %d\n", index_value);
		if (index_value <= pivot)
		{
			if (flag > 0)
			{
				do_pb(stack);
				//display(stack);
				index--;
			}
			else
				flag = 1;
			marker_value = find_value(stack->a, stack->index_a, marker);
			if (marker_value != index_value)
			{
				swap(stack, index);
				index++;
				size--;
			}
			else
			{
				index++;
				size--;
			}
		}
		else
		{
			index++;
			size--;
		}
	}
}

void	put_last_num(t_list *stack)
{
	int	last_num;
	int	num1;
	int	num2;
	int	num3;
	t_stack	*stack_b;

	stack_b = stack->b;
	last_num = stack->a->nb;
	num1 = stack_b->nb;
	num2 = stack_b->next->nb;
	num3 = stack_b->next->next->nb;
	//display(stack);
	if (last_num > num1)
		do_pb(stack);
	else if (last_num < num1 && last_num > num2)
	{
		do_pb(stack);
		do_sb(stack);
	}
	else if (last_num < num1 && last_num < num2 && last_num > num3)
	{
		do_rrb(stack);
		do_pb(stack);
		do_rb(stack);
		do_rb(stack);
	}
	else if (last_num < num3)
	{
		do_pb(stack);
		do_ra(stack);
	}
	//display(stack);
}

void	easy_sort(t_list *stack)
{
	int		num1;
	int		num2;
	int		num3;
	t_stack	*stack_b;

	//printf(">>>do easy swap<<<\n");
	do_pa(stack);
	stack_b = stack->b;
	num1 = stack_b->nb;
	num2 = stack_b->next->nb;
	num3 = stack_b->next->next->nb;
	if (num1 > num2 && num1 < num3)
		do_rrb(stack);
	else if (num1 > num2 && num2 > num3)
	{
		do_sb(stack);
		do_rrb(stack);
	}
	else if (num1 > num2 && num2 < num3)
	{
		do_rb(stack);
	}
	else if (num1 < num2 && num2 > num3)
	{
		do_sb(stack);
		do_rb(stack);
	}
	else if (num1 < num2 && num1 > num3)
		do_rrb(stack);
	do_sb(stack);
	do_rrb(stack);
	put_last_num(stack);
}

void	sort_base(t_list *stack)
{
	int	pivot;
	int	marker;
	int	index;

	index = 1;
	marker = 0;
	pivot = stack->pivot;
	//printf("start -> pivot = %d\n", pivot);
	while (!is_sort(stack))
	{
		quick_sort(stack, pivot, marker, index);
		pivot = last_num(stack->a);
		//printf(">>finish range<<\n");
	}
	if (stack_size(stack, 'b') > 4)
		stack->pivot = stack->b->nb;
	else
		easy_sort(stack);
}

void	pull_back(t_list *stack)
{
	t_stack *stack_b;

	stack_b = stack->b;
	while (stack_b)
	{
		do_pa(stack);
		stack_b = stack->b;
	}
}

void	sort(t_list *stack)
{
	//display(stack);
	stack->pivot = last_num(stack->a);
	while (!is_sort(stack) && !empty_b(stack))
	{
		sort_base(stack);
		pull_back(stack);
	}
	//display(stack);
}
