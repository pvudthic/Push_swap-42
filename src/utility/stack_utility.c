#include "../../push_swap.h"

int	last_num(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		current = current->next;
	}
	return (current->nb);
}

int	stack_size(t_list *stack, char name)
{
	int		size;
	t_stack	*current;

	size = 0;
	if (name == 'a')
		current = stack->a;
	else
		current = stack->b;
	while (current->next)
	{
		size++;
		current = current->next;
		if (!current->next)
			size++;
	}
	if (name == 'a')
		stack->size_a = size;
	else if (name == 'a')
		stack->size_b = size;
	return (size);
}

void	display_stack(t_list *stack)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_index *i_a;
	t_index *i_b;

	i_a = stack->index_a;
	i_b = stack->index_b;
	current_a = stack->a;
	current_b = stack->b;
	(void) i_b;
	printf("|------- a --------|     |------- b --------|   \n");
	printf("|  i		s  |     |  i		s   |\n");
	printf("| [%d]		:%d |     |   		    |\n", i_a->index, i_a->sorted);
	i_a = i_a->next;
	while (current_a || current_b)
	{
		if (current_a)
			printf("| [%d]	 %d	:%d |     ", i_a->index, current_a->nb, i_a->sorted);
		else if (!current_a)
			printf("[ ]  	 		");
		if (current_b)
			printf("%d     [i]\n", current_b->nb);
		else if (!current_b)
			printf("| [ ]	  	:   |\n");
		if (current_a)
		{
			current_a = current_a->next;
			i_a = i_a->next;
		}
		if (current_b)
			current_b = current_b->next;
	}
	printf("|------------------|     |------------------|");
}
