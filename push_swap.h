#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/// This should be deleted//
# include <stdio.h>
///////////////////////////

typedef struct a_list
{
	int				nb;
	struct a_list	*next;
}	t_sa;

typedef struct b_list
{
	int				nb;
	struct b_list	*next;
}	t_sb;

typedef struct l_list
{
	int		error;
	t_sa	*a;
	t_sb	*b;
}	t_s;

/// display function ///
void	display_stack(t_s *stack);
////////////////////////

void	create_sa_sb(int nb, t_s *stack);
t_s		*create_stack(int argc, char *first_input_arg);
int		parse_number(char *str, t_s *stack);
void	free_stack_ab(t_s *stack);
void	check_duplicate(int nb, t_sa *stack_a, t_s *stack);
void	error_exit(t_s *stack);
int		main(int argc, char **argv);

#endif
