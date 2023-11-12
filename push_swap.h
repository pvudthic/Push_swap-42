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

/*         display stack         */
void	display_stack(t_s *stack);

/*        stack operation        */
void	do_sa(t_s *stack);
void	do_sb(t_s *stack);
void	do_ss(t_s *stack);
void	do_pa(t_s *stack);
void	do_pb(t_s *stack);
void	do_ra(t_s *stack);
void	do_rb(t_s *stack);
void	do_rr(t_s *stack);
void	do_rra(t_s *stack);
void	do_rrb(t_s *stack);
void	do_rrr(t_s *stack);

/*            sorting            */
void	sort(t_s *stack);

/*         create stack         */
void	create_sa_sb(int nb, t_s *stack);
t_s		*create_stack(int argc, char *first_input_arg);
int		parse_number(char *str, t_s *stack);

/*           utility           */
void	free_stack_ab(t_s *stack);
void	check_duplicate(int nb, t_sa *stack_a, t_s *stack);
void	error_exit(t_s *stack);

/*             main            */
int		main(int argc, char **argv);

#endif
