#include "push_swap.h"

/*create stack a & b*/
	/*sort stack*/
		/*sorting*/
			/*algorithm*/
	//How do we print ?
		//1. print lasted ?
		//2. print for each instruction -> if malloc failed we going to shit
		//decide when finish  11 stack operation is finish
	/**/

s_list	*create_sb(s_list *stack_a)
{
	s_list	*stack;
	size_t	i;

	i = 0;
	stack = (s_list *)malloc(sizeof(s_list));
	if (!stack)
		return (NULL);
	while (i < stack_a->size)
	{

	}
	return ()
}

s_list	*create_sa(char *nb)
{
	s_list	*stack;

	stack = (s_list *)malloc(sizeof(s_list));
	if (!stack)
		return (NULL);
	while (*nb >= '0' && *nb <= '9' && *nb == ' ')
	{
		stack->nb = ft_atoi()
	}
	return (stack);
}

int	sort_stack(s_list *stack_a)
{
	s_list	*stack_b;

	if (!stack_a)
		return (0);
	else
	{
		stack_b = create_sb(stack_a);
		if (!stack_b)
			return (0);
	}

	return (0);
}

void	push_swap(char *nb)
{
	int	rt;

	rt = sort_stack(create_sa(nb));
	if (rt == 0)
	{
		/*clear node function*/
		return ;
	}
}

//int	main(int argc, char **argv)
int	main(void)
{
	char	nb[6] = "1 4 3";
	printf("--- Input Number ---\n%s", nb);
	push_swap(nb);
	return 0;
}
