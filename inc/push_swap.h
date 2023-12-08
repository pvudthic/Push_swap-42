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
void	base_sort(t_list *stack, int size, int position);
void	create_rank(t_list *stack);
/*Debugger*/
//void	display(t_list *stack);
//void	display_tmp(t_list *stack);
//void	display_position(t_list *stack);
/*Sort utillity*/
t_stack	*shift_start(t_stack *ref, int start);
int		find_pivot(t_stack *ref, int start);
int		find_start(t_stack *ref, int pivot);
int		find_sort_size(t_stack *ref, int start, int pivot);
/*Partition*/
void	partition_pos1(t_list *stack, int size, int max_range);
void	partition_pos2(t_list *stack, int size, int max_range);
void	partition_pos3(t_list *stack, int size, int max_range);
void	partition_pos4(t_list *stack, int size, int max_range);
void	first_partition(t_list *stack);
int		minimum(t_stack *ref, int size);
/*Easy sort utillity*/
int		find_next(t_stack *marker);
int		find_prev(t_stack *ref, t_stack *marker);
/*Range sort utillity*/
char	find_stack_name(t_list *ref, int max_range);
bool	is_sort(t_list *ref, char name, int max_range);
int		range_size(t_stack *stack, int max_range);
#endif
