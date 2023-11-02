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
	sb = create_stack_b(sb, ft_lstsize(sa));
	if (!sb)
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
