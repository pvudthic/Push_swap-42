/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:23:41 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/13 14:04:59 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

static void	update_position(t_list *stack, char target)
{
	stack->top_a = stack->a;
	stack->top_b = stack->b;
	if (target == 'a')
	{
		if (stack->size_a == 2)
			stack->bottom_a = stack->a->next;
		else if (stack->size_a == 1)
			stack->bottom_a = stack->a;
		if (stack->size_b <= 1)
			stack->bottom_b = stack->b;
	}
	else if (target == 'b')
	{
		if (stack->size_b == 2)
			stack->bottom_b = stack->b->next;
		else if (stack->size_b == 1)
			stack->bottom_b = stack->b;
		if (stack->size_a <= 1)
			stack->bottom_a = stack->a;
	}
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
		if (show_output("pa\n", stack->show_output) == -1)
			error_exit(stack);
		stack->size_a += 1;
		stack->size_b -= 1;
		update_position(stack, 'a');
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
		if (show_output("pb\n", stack->show_output) == -1)
			error_exit(stack);
		stack->size_a -= 1;
		stack->size_b += 1;
		update_position(stack, 'b');
	}
	else
		return ;
}
