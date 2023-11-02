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
	int				size_a;
	struct l_list	*next;
}					s_list;

char	*parse_number(s_list *stack, char *nb);
s_list	*create_stack_b(s_list *stack, int size);
s_list	*create_stack(s_list *stack, char *nb);
s_list	*ft_newnode(void);
int	ft_lstsize(s_list *lst);
int	main(void);
//int	main(int argc, char **argv);

#endif
