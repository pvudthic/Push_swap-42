#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "stack.h"

/// This should be deleted//
# include <stdio.h>
///////////////////////////

int		main(int argc, char **argv);


/*sort function*/
void	sort(t_list *stack);
void	easy_sort(t_list *stack, int start, int pivot);
void	create_rank(t_list *stack);

/*Debugger*/
void	display(t_list *stack);
void	display_tmp(t_list *stack);

/*Utillity*/
t_stack	*shift_start(t_stack *ref, int start);
int		find_pivot(t_stack *ref, int start);
int		find_start(t_stack *ref, int pivot);
int		find_sort_size(t_stack *ref, int start, int pivot);

#endif
