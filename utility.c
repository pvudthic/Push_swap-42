#include "push_swap.h"

///////////Form LIBFT///////////
int	ft_lstsize(s_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
///////////////////////////////

s_list	*create_stack_b(s_list *stack, int size)
{
	s_list	*current;

	printf("size of b: %d\n", size);
	stack = ft_newnode();
	if (!stack)
		return (0);
	stack = current;
	while (size > 0)
	{
		current->next = ft_newnode();
		current = current->next;
		if (!current)
		{
			/*free stack*/
			return (0);
		}
		printf("sb -> %d &%p\n", current->nb, current);
		size--;
	}
	return (stack);
}

s_list	*create_stack(s_list *stack, char *nb)
{
	s_list *current;

	stack = ft_newnode();
	if (!stack)
		return (0);
	current = stack;
	while (*nb != '\0')
	{
		nb = parse_number(current, nb);
		if (!nb)
		{
			/*free stack*/
			return (NULL);
		}
		printf("sa -> %d &%p\n", current->nb, current);
		if (*nb != '\0')
		{
			current->next = ft_newnode();
			current = current->next;
		}
	}
	return (stack);
}

s_list	*ft_newnode(void)
{
	s_list	*stack;

	stack = (s_list *)malloc(sizeof(s_list));
	if (!stack)
		return (0);
	stack->nb = 0;
	stack->next = NULL;
	return (stack);
}
char	*parse_number(s_list *stack, char *nb)
{
	int	i;
	int	n;
	int	res;

	res = 0;
	i = 0;
	n = 1;
	if (*nb < '0' || *nb > '9')
		return (0);
	if (*nb == '-')
			n = -1;
	while (*nb >= '0' && *nb <= '9')
	{
		res = (*nb - '0') + (res * 10);
		nb++;
		if (*nb == ' ')
		{
			nb++;
			break;
		}
	}
	if ((*nb <'0' || *nb > '9') && *nb != '\0')
		return (0);
	stack->nb = res;
	return (nb);
}
