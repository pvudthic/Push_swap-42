#include "mem_handle.h"

t_stack	*alloc_stack(t_list *lst, t_stack *stack, int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_exit(lst);
	new->nb = nb;
	new->sort = 0;
	new->position = 1;
	new->range = 1;
	new->next = stack;
	stack = new;
	return (new);
}

t_list	*alloc_list(void)
{
	t_list	*stack;

	stack = NULL;
	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		error_exit(NULL);
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
	stack->show_output = 0;
	return (stack);
}
