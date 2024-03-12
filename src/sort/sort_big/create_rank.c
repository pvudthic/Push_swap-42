/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:02 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 13:24:03 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	find_rank(t_stack *stack_a, t_stack *stack_tmp)
{
	int		rank;
	t_stack	*current_tmp;

	current_tmp = stack_tmp;
	rank = 1;
	while (current_tmp)
	{
		if (current_tmp->nb == stack_a->nb)
		{
			stack_a->nb = rank;
			return ;
		}
		current_tmp = current_tmp->next;
		rank++;
	}
}

void	create_rank(t_list *stack)
{
	t_stack	*stack_a;
	t_stack	*stack_tmp;
	int		pivot;
	int		start;

	create_stack_tmp(stack);
	pivot = find_pivot(stack->tmp, stack->tmp->nb);
	start = find_start(stack->tmp, pivot);
	easy_sort(stack, start, pivot);
	stack_a = stack->a;
	stack_tmp = stack->tmp;
	while (stack_a)
	{
		find_rank(stack_a, stack_tmp);
		stack_a = stack_a->next;
	}
}
