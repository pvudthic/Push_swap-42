/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_position_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:17 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 13:24:18 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	case_bot_1(t_list *stack)
{
	do_rra(stack);
	do_pb(stack);
	do_rra(stack);
	do_rra(stack);
	compare_swap(stack, 3);
	do_pa(stack);
}

static void	case_bot_2(t_list *stack, int mid)
{
	do_rra(stack);
	do_rra(stack);
	if (mid == 3)
	{
		do_sa(stack);
		do_rra(stack);
	}
	else if (mid == 1)
	{
		do_pb(stack);
		do_rra(stack);
		do_sa(stack);
		do_pa(stack);
	}
}

static void	case_bot_3(t_list *stack)
{
	do_rra(stack);
	do_rra(stack);
	do_rra(stack);
	compare_swap(stack, 3);
}

void	sort3_position_3(t_list *stack)
{
	int	top;
	int	mid;
	int	bot;

	stack->n_1 = stack->range_stack->nb;
	stack->n_2 = stack->range_stack->next->nb;
	stack->n_3 = stack->range_stack->next->next->nb;
	assign_lane(stack, &top, &mid, &bot);
	if (bot == 3)
		case_bot_3(stack);
	else if (bot == 2)
		case_bot_2(stack, mid);
	else
		case_bot_1(stack);
}
