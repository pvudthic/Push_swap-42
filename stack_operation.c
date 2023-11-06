#include "push_swap.h"

///// Display function /////////
void	display_stack(s_list *stack, char name)
{
	printf("stack : %c\n", name);
	while (stack != NULL)
	{
		printf("%d\n", stack->nb);
		stack = stack->next;
	}
}
////////////////////////////////

s_list	*check_error(s_list *h_stack, int error)
{
	s_list	*current_stack;

	if (error == 1)
	{
		while (h_stack != NULL)
		{
			current_stack = h_stack->next;
			printf("\nfreeing.. nb: %d", h_stack->nb);
			free(h_stack);
			h_stack = current_stack;
		}
		return (NULL);
	}
	return (h_stack);
}

s_list	*new_stack(void)
{
	s_list	*stack;

	stack = (s_list *)malloc(sizeof(s_list));
	if (!stack)
		return (NULL);
	stack->nb = 0;
	stack->error = 0;
	stack->size = 0;
	stack->index = 0;
	stack->next = NULL;
	return (stack);
}

s_list	*add_stack_b(int size)
{
	s_list	*h_stack;
	s_list	*current_stack;
	int		i;

	i = 1;
	if (size > 0)
	{
		h_stack = new_stack();
		if (!h_stack)
			return (NULL);
		current_stack = h_stack;
		while (i != size)
		{
			current_stack->next = new_stack();
			if (!current_stack->next)
				return (check_error(h_stack, 1));
			current_stack = current_stack->next;
			i++;
		}
	}
	return (h_stack);
}

void	convert_string(s_list *h_stack, s_list *stack, char *str, int n, int i)
{
	int	res;

	while (str[i] >= '0' && str[i] <= '9' && h_stack->error == 0)
		res = (str[i++] - '0') + (res * 10);
	if (str[i] != ' ' && str[i] != '\0')
		h_stack->error = 1;
	else if (str[i] == ' ' && ((str[i + 1] < '0' || str[i + 1] > '9') && str[i+1] != '-'))
		h_stack->error = 1;
	else if (str[i] == ' ')
		i++;
	if (h_stack->error != 1)
	{
		h_stack->index += i;
		stack->nb = (res * n);
	}
}

void	parse_number(s_list *h_stack, s_list *stack, char *str)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	if ((str[0] < '0' || str[0] > '9') && str[i] != '-')
		h_stack->error = 1;
	if (str[i] == '-')
	{
		if ((str[i + 1] < '0' || str[i + 1] > '9'))
			h_stack->error = 1;
		n = -1;
		i++;
	}
	convert_string(h_stack, stack, str + i, n, i);
}

s_list	*create_stack(char *str)
{
	s_list	*h_stack;
	s_list	*current_stack;
	int		size;

	size = 1;
	h_stack = new_stack();
	if (!h_stack)
		return (NULL);
	current_stack = h_stack;
	while (str[h_stack->index] != '\0' && h_stack->error == 0)
	{
		parse_number(h_stack, current_stack, str + h_stack->index);
		if (str[h_stack->index] != '\0' && h_stack->error == 0)
		{
			current_stack->next = new_stack();
			if (!current_stack->next)
				h_stack->error = 1;
			current_stack = current_stack->next;
			size++;
		}
	}
	h_stack->size = size;
	return (check_error(h_stack, h_stack->error));
}
