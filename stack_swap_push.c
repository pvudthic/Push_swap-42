#include "push_swap.h"

/*Cuation If there nothing doesn't do anything so we have to empty stack*/

void	do_sa(t_list *stack)
{
	int	tmp;

	tmp = stack->a->next->nb;
	stack->a->next->nb = stack->a->nb;
	stack->a->nb = tmp;
	printf("sa\n");
}

void	do_sb(t_list *stack)
{
	int	tmp;

	tmp = stack->b->next->nb;
	stack->b->next->nb = stack->b->nb;
	stack->b->nb = tmp;
	printf("sb\n");
}

void	do_ss(t_list *stack)
{
	int	tmp;

	tmp = stack->a->next->nb;
	stack->a->next->nb = stack->a->nb;
	stack->a->nb = tmp;
	tmp = stack->b->next->nb;
	stack->b->next->nb = stack->b->nb;
	stack->b->nb = tmp;
	printf("ss\n");
}

void	do_pa(t_list *stack)
{
	t_stack	*tmp_stack;

	tmp_stack = stack->b;
	stack->b = stack->b->next;
	tmp_stack->next = stack->a;
	stack->a = tmp_stack;
	printf("pa\n");
}

void	do_pb(t_list *stack)
{
	t_stack	*tmp_stack;

	tmp_stack = stack->a;
	stack->a = stack->a->next;
	tmp_stack->next = stack->b;
	stack->b = tmp_stack;
	printf("pb\n");
}
