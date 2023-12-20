#include "libft.h"
#include "stack.h"
#include "free_mem.h"


static void swap_strings(char **str, int first, int last)
{
	char *temp;

	temp = str[first];
	str[first] = str[last];
	str[last] = temp;
}
/*
	This function will handle split data and
	convert upside down position
*/
char	**split_to_stack(t_list *stack, char *str)
{
	char	**data;
	int		num_elements;
	int		start;
	int		end;

	num_elements = 0;
	data = ft_split(str, ' ');
	if (!data)
		error_exit(stack);
	while (data[num_elements]) // Counter number of element in group of string
		num_elements++;
	start = 0;
	end = num_elements - 1;
	while (start < end)
	{
		swap_strings(data, start, end);
		start++;
		end--;
	}
	return (data);
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
