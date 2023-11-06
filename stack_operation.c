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

s_list	*new_stack(void)
{
	s_list	*stack;

	stack = (s_list *)malloc(sizeof(s_list));
	if (!stack)
		return (NULL);
	stack->nb = 0;
	stack->error = 0;
	stack->size = 0;
	stack->str_index = 0;
	stack->next = NULL;
	return (stack);
}

s_list	*create_stack_b(int size)
{
	s_list	*head_stack;
	s_list	*current_stack;
	int		i;

	i = 1;
	if (size > 0)
	{
		head_stack = new_stack();
		if (!head_stack)
			return (NULL);
		current_stack = head_stack;
		while (i != size)
		{
			current_stack->next = new_stack();
			if (!current_stack->next)
			{
				/*clear stack*/
				return (NULL);
			}
			current_stack = current_stack->next;
			i++;
		}
	}
	return (head_stack);
}

void	parse_number(s_list *head_stack, s_list *stack, char *str)
{
	int	n;
	int	i;
	int	res;
	int	check;

	n = 1;
	i = 0;
	res = 0;
	//Check first character
	if ((str[0] < '0' && str[0] > '9') && str[i] != '-')
	{
		printf("error first character");
		head_stack->error = 1;
		return ;
	}
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	// Not a space and NULL-Terminated
	if (str[i] != ' ' && str[i] != '\0')
	{
		printf("Not a space and NULL-Terminated it a \n%c\n", str[i]);
		head_stack->error = 1;
	}
	// If it space next character must be number or negative sign
	else if (str[i] == ' ' && ((str[i + 1] < '0' || str[i + 1] > '9') && str[i+1] != '-'))
		head_stack->error = 1;
	// If it just a space
	else if (str[i] == ' ')
		i++;
	head_stack->str_index += i;
	stack->nb = (res * n);
}

s_list	*create_stack(char *str)
{
	s_list	*head_stack;
	s_list	*current_stack;
	int		size;
	int		i;

	i = 0;
	size = 1;
	head_stack = new_stack();
	if (!head_stack)
		return (NULL);
	current_stack = head_stack;
	while (str[i] != '\0' && head_stack->error == 0)
	{
		parse_number(head_stack, current_stack, str + i);
		i = head_stack->str_index;
		if (str[i] != '\0' && head_stack->error == 0)
		{
			current_stack->next = new_stack();
			if (!current_stack->next)
				head_stack->error = 1;
			current_stack = current_stack->next;
			size++;
		}
	}
	if (head_stack->error == 1)
		{
			/*clear stack*/
			return (0);
		}
	head_stack->size = size;
	return (head_stack);
}
