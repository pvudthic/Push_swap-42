#include "stack.h"

static int	count_elements(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

static char	**split_to_stack(t_list *stack, char *str)
{
	char	**data;
	char	*temp;
	int		num_elements;
	int		start;
	int		end;

	data = ft_split(str, ' ');
	if (!data)
		error_exit(stack);
	num_elements = count_elements(data);
	start = 0;
	end = num_elements - 1;
	while (start < end)
	{
		temp = data[start];
		data[start] = data[end];
		data[end] = temp;
		start++;
		end--;
	}
	return (data);
}

/* starting from last argument for stack behavior */
static void	add_data(t_list *stack, int argc, char **argv)
{
	int		nb;
	char	**data;
	char	**head;

	argc--;
	while (argc > 0)
	{
		data = split_to_stack(stack, argv[argc]);
		head = data;
		while (*head)
		{
			nb = convert_nb(*head, stack);
			check_duplicate(nb, stack);
			stack->a = alloc_stack(stack, stack->a, nb);
			head++;
		}
		data = free_split(data);
		argc--;
	}
	stack->t_size = stack_size(stack, 'a');
}

/* Create 2 stack from input argument */
t_list	*init_stack(int argc, char **argv)
{
	t_list *new_list;

	if (!*argv[1])
		error_exit(NULL);
	new_list = alloc_list();
	add_data(new_list, argc, argv);
	return (new_list);
}
