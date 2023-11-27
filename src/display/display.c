#include "../../push_swap.h"

static void	display_start_index(t_index *i_a)
{
	int		tmp;

	if (i_a->index > 0)
	{
		tmp = 0;
		while (tmp < i_a->index)
		{
			printf("| [%d]	  	  :   :  |     | [ ]	  	  :1  :1 |\n", tmp);
			tmp++;
		}
	}
}

void	display_stack(t_list *stack)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_index *i_a;
	t_index *i_b;

	i_a = stack_start_index(stack->index_a, stack_size(stack, 'a'), stack->index_size);
	i_b = stack->index_b;
	current_a = stack->a;
	current_b = stack->b;
	(void) i_b;
	printf("|--------- a ------------|     |---------- b ------------|   \n");
	printf("|  i	   v	  s    e |     |  i	   v	  s    e |\n");
	display_start_index(i_a);
	printf("| [%d]	  	  :%d  :%d |     | [ ]	  	  :1  :1 |\n", i_a->index, i_a->sorted, i_a->edge);
	i_a = i_a->next;
	while (current_a || current_b)
	{
		if (current_a)
			printf("| [%d]	   %d	  :%d  :%d |     ", i_a->index, current_a->nb, i_a->sorted, i_a->edge);
		else if (!current_a)
			printf("| [ ]	    	  :   :  |     ");
		if (current_b)
			printf("| [ ]	   %d	  :   :  |\n", current_b->nb);
		else if (!current_b)
			printf("| [ ]	    	  :   :  |     \n");
		if (current_a)
		{
			current_a = current_a->next;
			i_a = i_a->next;
		}
		if (current_b)
			current_b = current_b->next;
	}
	printf("|------------------------|     |-------------------------|\n");
}
