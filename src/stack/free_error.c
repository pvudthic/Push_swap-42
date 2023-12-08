#include "stack.h"

void	check_duplicate(int nb, t_list *stack)
{
	t_stack	*head_stack;

	head_stack = stack->a;
	while (head_stack)
	{
		if (nb == head_stack->nb)
		{
			error_exit(stack);
		}
		head_stack = head_stack->next;
	}
}


size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	error_exit(t_list *stack)
{
	if (stack)
		free_stack_ab(stack);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_stack_ab(t_list *stack)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (stack->a)
	{
		while (stack->a)
		{
			tmp_a = stack->a;
			stack->a = stack->a->next;
			free(tmp_a);
		}
	}
	if (stack->b)
	{
		while (stack->b)
		{
			tmp_b = stack->b;
			stack->b = stack->b->next;
			free(tmp_b);
		}
	}
	free(stack);
}
