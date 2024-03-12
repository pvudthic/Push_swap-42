/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_position_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:19 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 13:24:20 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	do_simple(t_list *stack)
{
	do_rrb(stack);
	do_rrb(stack);
	do_rrb(stack);
	do_pa(stack);
	do_pa(stack);
	do_pa(stack);
}

static int	reverse_rotate_counter(int top, int mid)
{
	if (top == 3)
		return (3);
	else if (mid == 3)
		return (2);
	return (1);
}

void	sort3_position_4(t_list *stack)
{
	int	top;
	int	mid;
	int	bot;
	int	max_rotate;
	int	remain;

	stack->n_1 = stack->range_stack->nb;
	stack->n_2 = stack->range_stack->next->nb;
	stack->n_3 = stack->range_stack->next->next->nb;
	assign_lane(stack, &top, &mid, &bot);
	if (top == 3 && mid == 2 && bot == 1)
	{
		do_simple(stack);
		return ;
	}
	max_rotate = reverse_rotate_counter(top, mid);
	remain = 3 - max_rotate;
	while (max_rotate--)
		do_rrb(stack);
	do_pa(stack);
	while (remain--)
		do_rrb(stack);
	do_pa(stack);
	do_pa(stack);
	compare_swap(stack, 1);
}
