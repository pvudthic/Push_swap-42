/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:23:39 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 13:23:40 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	target_stack(t_list *stack, char target, char move)
{
	if (target == 'a' && move == 'p')
		do_pa(stack);
	else if (target == 'a' && move == 's')
		do_sa(stack);
	else if (target == 'a' && move == 'r')
		do_ra(stack);
	else if (target == 'a' && move == 'x')
		do_rra(stack);
	else if (target == 'b' && move == 'p')
		do_pb(stack);
	else if (target == 'b' && move == 's')
		do_sb(stack);
	else if (target == 'b' && move == 'r')
		do_rb(stack);
	else if (target == 'b' && move == 'x')
		do_rrb(stack);
	else if (target == 's' && move == 's')
		do_ss(stack);
	else if (target == 'r' && move == 'r')
		do_rr(stack);
	else if (target == 'r' && move == 'x')
		do_rrr(stack);
	else
		return (-1);
	return (1);
}

static int	decode(char *set, t_list *stack)
{
	if (set[0] == 'p' && set[2] == '\n')
		return (target_stack(stack, set[1], 'p'));
	else if (set[0] == 's' && set[2] == '\n')
		return (target_stack(stack, set[1], 's'));
	else if (set[0] == 'r')
	{
		if (set[1] == 'r' && set[3] == '\n')
			return (target_stack(stack, set[2], 'x'));
		else if (set[2] == '\n')
			return (target_stack(stack, set[1], 'r'));
	}
	return (-1);
}

static char	encode(char inst)
{
	if (inst == 'p')
		return ('p');
	else if (inst == 's')
		return ('s');
	else if (inst == 'r')
		return ('r');
	else if (inst == 'a')
		return ('a');
	else if (inst == 'b')
		return ('b');
	else if (inst == '\n')
		return ('\n');
	else
		return ('E');
}

static bool	run_instruction(t_list *stack, char *inst, char *current)
{
	int		i;
	char	c_set[5];

	i = 0;
	ft_bzero(c_set, 5);
	while (*current)
	{
		c_set[i] = encode(*current);
		if (c_set[i] == 'E')
			free_er(inst, NA, stack);
		if (c_set[i] == '\n')
		{
			if (decode(c_set, stack) == -1)
				free_er(inst, NA, stack);
			i = 0;
		}
		else
		{
			if (++i > 5)
				free_er(inst, NA, stack);
		}
		current++;
	}
	return (is_sort(stack));
}

int	main(int argc, char *argv[])
{
	t_list	*stack;
	char	*inst;
	char	*result[1];
	bool	sorted;

	if (argc > 1)
	{
		stack = init_stack(argc, argv);
		inst = read_instruction(FD_STDOUT, stack);
		sorted = run_instruction(stack, inst, inst);
		if (sorted)
			result[0] = "OK\n";
		else if (!sorted)
			result[0] = "KO\n";
		if (write(1, result[0], 3) == -1)
			free_er(inst, NA, stack);
		free(inst);
		clear_data(stack);
	}
}
