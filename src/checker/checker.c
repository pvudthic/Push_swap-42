#include "checker.h"
#include "debugger.h"

static bool	is_sort(t_list *ref)
{
	t_stack	*current;

	if (ref->b)
		return (false);
	current = ref->a;
	while (current->next != NULL)
	{
		if ((current->nb > current->next->nb))
			return (false);
		current = current->next;
	}
	return (true);
}

void	free_er(char *str1, char *str2, t_list *stack)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	error_exit(stack);
}

char	*read_instruction(int fd, t_list *stack)
{
	int		rd;
	char	*buf;
	char	*old_data;
	char	*data;

	data = NULL;
	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
		free_er(NA, NA, stack);
	rd = 1;
	while (rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			free_er(buf, data, stack);
		buf[rd] = 0;
		old_data = data;
		data = ft_strjoin(data, buf);
		if (!data)
			free_er(buf, data, stack);
		free(old_data);
	}
	free(buf);
	return (data);
}

int	target_stack(t_list *stack, char target, char move)
{
	if (target == 'a' && move == 'p')
		do_pa(stack);
	else if (target == 'a'  && move == 's')
		do_sa(stack);
	else if (target == 'a'  && move == 'r')
		do_ra(stack);
	else if (target == 'a'  && move == 'x')
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

int	decode(char *set, t_list *stack)
{
	//printf("decoding '%c' '%c' '%c' '%c'\n", set[0], set[1], set[2], set[3]);
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

char	encode(char inst)
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

bool	run_instruction(t_list *stack, char *inst, char *current)
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
