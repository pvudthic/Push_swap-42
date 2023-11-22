#include "push_swap.h"

int	init_stack_index(t_stack *stack, int stop)
{
	t_stack	*current;
	int		i;

	i = 1;
	current = stack;
	while (i != stop + 1)
	{
		current->index = i;
		i++;
		if (current->next == NULL)
			return (current->nb);
		current = current->next;
	}
	return (current->nb);
}

int		find_index(t_stack *stack, int pos)
{
	int		stop;
	t_stack	*current;

	stop = 1;
	current = stack;
	while (current)
	{
		if (current->nb == pos)
			break;
		stop++;
		current = current->next;
	}
	return (stop);
}

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

void	swap_handle(t_list *stack, int start, int stop)
{
	if (stop == 1)
		easy_swap(stack, start);
	else
		length_swap(stack, start, stop);
}

void	swap(t_list *stack, int pos, int target)
{
	int	start;
	int	stop;

	start = find_index(stack->a, target);
	stop = find_index(stack->a, pos);
	stop = stop - start;
	//printf("stop %d start %d\n", stop, start);
	swap_handle(stack, start, stop);
	//display_stack(stack);
}

int		quickSort(t_list *stack, int pivot, int pos, int target)
{
	int		size;
	t_stack	*marker;
	t_stack	*current;

	current = stack->a;
	marker = NULL;
	size = stack->size_a;
	while (size > 0)
	{
		pos = current->nb;
		if (pos <= pivot)
		{
			//printf("%d <= %d\n", pos, pivot);
			if (marker)
				marker = marker->next;
			else
				marker = stack->a;
			target = marker->nb;
			if (pos != target)
			{
				printf("do swap %d <-> %d\n", pos, target);
				swap(stack, pos, target);
				display_stack(stack);
			}
		}
		/*shifting section*/
		size--;
		current = current->next;
	}
	printf("here");
	init_stack_index(stack->a, stack->size_a);
	display_stack(stack);
	/*We should use recursive function*/
	return (0);
}

void	sort(t_list *stack)
{
	stack_size(stack, 'a');
	init_stack_index(stack->a, stack->size_a);
	//display_stack(stack);
	quickSort(stack, last_num(stack->a), 0, 0);
}
