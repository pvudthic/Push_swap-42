#include "push_swap.h"

void	push_swap(char *nb)
{
	s_list	*sa;
	s_list	*sb;
	int		i;

	i = 0;
	sa = create_stack(nb);
	if (!sa)
		return ;
	sb = create_stack_b(sa->size);
	if (!sb)
		return ;
	display_stack(sa, 'a');
	display_stack(sb, 'b');
}
//int	main(int argc, char **argv)
int	main(void)
{
	char	nb[1000] = "1 4 3 1000 100000 123598234";
	printf("--- Input Number ---\n");
	push_swap(nb);
	return 0;
}


//check error condition
// if ((nb[i] < '0' || nb[i] > '9'))
// {
// 	//first character is not number
// 	if (i == 0)
// 		head_stack->error = 1;
// 	// Not a space and not a number
// 	else if ((nb[i] < '0' || nb[i] > '9') && nb[i] != ' ')
// 		head_stack->error = 1;
// 	// Not first character and it space but next character not number
// 	else if (nb[i] == ' ' && (nb[i + 1] < '0' || nb[i + 1] > '9'))
// 		head_stack->error = 1;
// 	// If it just a space
// 	else if (nb[i] == ' ')
// 		head_stack->error = 0;
// }
