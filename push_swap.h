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

///display stack///
void	display_stack(s_list *stack, char name);
//////////////////

s_list	*new_stack(void);
void	convert_string(s_list *head_stack, s_list *stack, char *str, int n, int i);
void	parse_number(s_list *head_stack, s_list *stack, char *str);
s_list	*create_stack(char *str);
s_list	*add_stack_b(int size);
int	main(void);
//int	main(int argc, char **argv);

#endif
