#include "push_swap.h"

///// Display function /////////
void	display_stack(s_list *stack, char name)
{
	printf("\nstack :%c\n", name);
	while (stack != NULL)
	{
		printf("%d ", stack->nb);
		stack = stack->next;
	}
}
////////////////////////////////
