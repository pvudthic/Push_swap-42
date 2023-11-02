#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/// This should be deleted//
# include <stdio.h>
///////////////////////////

typedef struct l_list
{
	int				nb;
	struct l_list	*next;
}					s_list;

int	ft_atoi(const char *str);
int	main(void);
//int	main(int argc, char **argv);

#endif
