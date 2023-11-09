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
