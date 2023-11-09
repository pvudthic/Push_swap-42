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
	int				error;
	int				index;
	int				size;
	struct l_list	*next;
}					s_list;

int	main(int argc, char **argv);

#endif
