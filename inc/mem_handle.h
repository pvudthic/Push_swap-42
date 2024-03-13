/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:30:17 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 16:30:18 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_HANDLE_H
# define MEM_HANDLE_H

# define ERROR 0

# include "inc_stdlib.h"

typedef struct a_list
{
	int				nb;
	int				position;
	int				range;
	int				sort;
	struct a_list	*next;
	struct a_list	*prev;
}	t_stack;

typedef struct l_list
{
	int		pivot;
	int		max_range;
	int		t_size;
	int		size_a;
	int		size_b;
	int		n_1;
	int		n_2;
	int		n_3;
	int		show_output;
	t_stack	*a;
	t_stack	*b;
	t_stack	*top_a;
	t_stack	*bottom_a;
	t_stack	*top_b;
	t_stack	*bottom_b;
	t_stack	*tmp;
	t_stack	*range_stack;
}	t_list;

void	clear_data(t_list *stack);
t_list	*alloc_list(void);
t_stack	*alloc_stack(t_list *lst, t_stack *stack, int nb);
void	error_exit(t_list *stack);
char	**free_split(char **data);

#endif
