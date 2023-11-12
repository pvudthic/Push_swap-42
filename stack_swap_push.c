#include "push_swap.h"

/*Cuation If there nothing doesn't do anything so we have to empty stack*/

void	do_sa(t_list *stack)
{
	int	tmp;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a->next->nb;
		stack->a->next->nb = stack->a->nb;
		stack->a->nb = tmp;
		printf("sa\n");
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
		printf("ss\n");
	}
	else
		return ;
}

void	do_pa(t_list *stack)
{
	t_stack	*tmp_stack;

	if (stack->b)
	{
		tmp_stack = stack->b;
		stack->b = stack->b->next;
		tmp_stack->next = stack->a;
		stack->a = tmp_stack;
		printf("pa\n");
	}
	else
		return ;
}

void	do_pb(t_list *stack)
{
	t_stack	*tmp_stack;

	if (stack->a)
	{
		tmp_stack = stack->a;
		stack->a = stack->a->next;
		tmp_stack->next = stack->b;
		stack->b = tmp_stack;
		printf("pb\n");
	}
	else
		return ;
}
