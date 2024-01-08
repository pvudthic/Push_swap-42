#include "mem_handle.h"

void	error_exit(t_list *stack)
{
	clear_data(stack);
	write(2, "Error\n", 6);
	exit(1);
}
