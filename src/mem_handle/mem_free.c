/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:23:56 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 13:23:57 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_handle.h"

static void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	clear_data(t_list *stack)
{
	if (stack)
	{
		if (stack->tmp)
			free_stack(stack->tmp);
		if (stack->a)
			free_stack(stack->a);
		if (stack->b)
			free_stack(stack->b);
		free(stack);
	}
}

char	**free_split(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		data[i] = NULL;
		i++;
	}
	free(data);
	return (NULL);
}
