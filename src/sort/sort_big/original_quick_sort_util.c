/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   original_quick_sort_util.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:04 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 13:24:05 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	find_next(t_stack *marker)
{
	if (marker->next)
	{
		marker = marker->next;
		return (marker->nb);
	}
	return (marker->nb);
}

int	find_prev(t_stack *ref, t_stack *marker)
{
	t_stack	*stack_tmp;

	stack_tmp = ref;
	if (stack_tmp == marker)
		return (stack_tmp->nb);
	while (stack_tmp)
	{
		if (stack_tmp->next == marker)
			return (stack_tmp->nb);
		stack_tmp = stack_tmp->next;
	}
	return (stack_tmp->nb);
}
