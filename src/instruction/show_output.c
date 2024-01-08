#include "instruction.h"

int	show_output(char *str, int show)
{
	if (show == 0)
		return (1);
	if (ft_printf("%s", str) == -1)
		return (-1);
	return (1);
}
