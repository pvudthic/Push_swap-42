/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:23:41 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 13:23:42 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

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
		stack->top_a = stack->a;
		stack->top_b = stack->b;
		stack->size_a += 1;
		stack->size_b -= 1;
		if (stack->size_a == 2)
			stack->bottom_a = stack->a->next;
		else if (stack->size_a == 1)
			stack->bottom_a = stack->a;
		if (stack->size_b <= 1)
			stack->bottom_b = stack->b;
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
		stack->top_a = stack->a;
		stack->top_b = stack->b;
		stack->size_a -= 1;
		stack->size_b += 1;
		if (stack->size_b == 2)
			stack->bottom_b = stack->b->next;
		else if (stack->size_b == 1)
			stack->bottom_b = stack->b;
		if (stack->size_a <= 1)
			stack->bottom_a = stack->a;
	}
	else
		return ;
}
