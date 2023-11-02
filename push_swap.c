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
		printf("-> %d \n", current->nb);
		current->next = ft_newnode();
		current = current->next;
	}
	return (stack);
}
void	push_swap(char *nb)
{
	s_list	*sa;
	s_list	*sb;

	if ((*nb < '0' || *nb > '9') && *nb != '-')
	{
		printf("Error\n");
		return ;
	}
	sa = create_stack(sa, nb);
	if (!sa)
	{
		printf("Error\n");
		return ;
	}
}
//int	main(int argc, char **argv)
int	main(void)
{
	char	nb[6] = "1 4 3";
	printf("--- Input Number ---\n");
	push_swap(nb);
	return 0;
}
