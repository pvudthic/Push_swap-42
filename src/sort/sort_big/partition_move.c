/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:08 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 13:24:09 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	move_1_to_(t_list *stack, int max_range, int des)
{
	if (des == 4)
	{
		stack->top_a->position = 4;
		stack->top_a->range = max_range;
		do_pb(stack);
		do_rb(stack);
	}
	else if (des == 2)
	{
		stack->top_a->position = 2;
		stack->top_a->range = max_range + 1;
		do_pb(stack);
	}
	else if (des == 3)
	{
		stack->top_a->position = 3;
		stack->top_a->range = max_range + 2;
		do_ra(stack);
	}
}

void	move_2_to_(t_list *stack, int max_range, int des)
{
	if (des == 1)
	{
		stack->top_b->position = 1;
		stack->top_b->range = max_range + 2;
		do_pa(stack);
	}
	else if (des == 3)
	{
		stack->top_b->position = 3;
		stack->top_b->range = max_range + 1;
		do_pa(stack);
		do_ra(stack);
	}
	else if (des == 4)
	{
		stack->top_b->position = 4;
		stack->top_b->range = max_range;
		do_rb(stack);
	}
}

void	move_3_to_(t_list *stack, int max_range, int des)
{
	if (des == 1)
	{
		stack->bottom_a->position = 1;
		stack->bottom_a->range = max_range + 2;
		do_rra(stack);
	}
	else if (des == 2)
	{
		stack->bottom_a->position = 2;
		stack->bottom_a->range = max_range + 1;
		do_rra(stack);
		do_pb(stack);
	}
	else if (des == 4)
	{
		stack->bottom_a->position = 4;
		stack->bottom_a->range = max_range;
		do_rra(stack);
		do_pb(stack);
		do_rb(stack);
	}
}

void	move_4_to_(t_list *stack, int max_range, int des)
{
	if (des == 1)
	{
		stack->bottom_b->position = 1;
		stack->bottom_b->range = max_range + 2;
		do_rrb(stack);
		do_pa(stack);
	}
	else if (des == 3)
	{
		stack->bottom_b->position = 3;
		stack->bottom_b->range = max_range + 1;
		do_rrb(stack);
		do_pa(stack);
		do_ra(stack);
	}
	else if (des == 2)
	{
		stack->bottom_b->position = 2;
		stack->bottom_b->range = max_range;
		do_rrb(stack);
	}
}
