#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/// This should be deleted//
# include <stdio.h>
///////////////////////////

typedef struct b_list
{
	int nb;
	struct b_list *next;
} b_list;

typedef struct a_list
{
	int nb;
	struct a_list *next;
} a_list;

typedef struct l_list
{
	int error;
	struct a_list *a;
	struct b_list *b;
} s_list;

/// display function ///
void	display_stack(s_list *stack);
////////////////////////

void	free_stack_AB(s_list *stack);
void	create_stack(int nb, s_list *stack);
int		parse_number(char *str, s_list *stack);
void	error_exit(s_list *stack);
int		main(int argc, char **argv);

#endif
