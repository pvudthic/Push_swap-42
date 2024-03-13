/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:27 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/13 14:09:57 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	range_size(t_stack *stack, int max_range)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current)
	{
		if (current->range == max_range)
			size++;
		current = current->next;
	}
	return (size);
}

static int	find_position(t_list *stack, int max_range)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack->a;
	stack_b = stack->b;
	while (stack_a)
	{
		if (stack_a->range == max_range)
		{
			stack->range_stack = stack_a;
			return (stack_a->position);
		}
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		if (stack_b->range == max_range)
		{
			stack->range_stack = stack_b;
			return (stack_b->position);
		}
		stack_b = stack_b->next;
	}
	return (0);
}

static int	position_partition(t_list *stack, int size, int pos, int m_range)
{
	if (pos == 1)
		partition_pos1(stack, size, m_range);
	else if (pos == 2)
		partition_pos2(stack, size, m_range);
	else if (pos == 3)
		partition_pos3(stack, size, m_range);
	else if (pos == 4)
		partition_pos4(stack, size, m_range);
	return (m_range + 2);
}

static int	range_sort(t_list *ref, int max_range, int position)
{
	int		size;

	if (position == 1 || position == 3)
		size = range_size(ref->a, max_range);
	else
		size = range_size(ref->b, max_range);
	if (size <= 3)
	{
		base_sort_new(ref, size, position);
		return (max_range - 1);
	}
	else
		max_range = position_partition(ref, size, position, max_range);
	return (max_range);
}

void	big_sort(t_list *stack)
{
	int		position;
	int		max_range;

	create_rank(stack);
	first_partition(stack);
	max_range = stack->max_range - 1;
	while (max_range > 0)
	{
		position = find_position(stack, max_range);
		max_range = range_sort(stack, max_range, position);
	}
}
