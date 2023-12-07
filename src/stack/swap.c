#include "stack.h"
/*Cuation If there nothing doesn't do anything so we have to empty stack*/

/*Notes : We should update our bottom stack as well if size is > 1*/
/*
	Notes : We should collect information about stack size such as
	when we do_pa() or do_pb() we should decrease size of stack dynamically
*/
void	do_sa(t_list *stack)
{
	int	tmp;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a->next->nb;
		stack->a->next->nb = stack->a->nb;
		stack->a->nb = tmp;
		printf("sa\n");
		/* Handling Information*/
		stack->top_a = stack->a; /*adjust position*/
		if (stack->size_a == 2)
			stack->bottom_a = stack->a->next; /*adjust position*/
	}
	else
		return ;
}

void	do_sb(t_list *stack)
{
	int	tmp;

	if (stack->b && stack->b->next)
	{
		tmp = stack->b->next->nb;
		stack->b->next->nb = stack->b->nb;
		stack->b->nb = tmp;
		printf("sb\n");
		/* Handling Information*/
		stack->top_b = stack->b; /*adjust position*/
		if (stack->size_b == 2)
			stack->bottom_b = stack->b->next; /*adjust position*/
	}
	else
		return ;
}

void	do_ss(t_list *stack)
{
	int	tmp;

	if (stack)
	{
		if (stack->a && stack->a->next)
		{
			tmp = stack->a->next->nb;
			stack->a->next->nb = stack->a->nb;
			stack->a->nb = tmp;
		}
		if (stack->b && stack->b->next)
		{
			tmp = stack->b->next->nb;
			stack->b->next->nb = stack->b->nb;
			stack->b->nb = tmp;
		}
		stack->top_a = stack->a; /*adjust position*/
		stack->top_b = stack->b; /*adjust position*/
		printf("ss\n");
	}
	else
		return ;
}
