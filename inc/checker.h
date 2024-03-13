/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:30:09 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 16:30:10 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define NA 0
# define FD_STDOUT 0
# define BUFFER_SIZE 1
# define KO 0
# define OK 1
# define FORMAT_ERROR 2

# include "inc_stdlib.h"
# include "instruction.h"
# include "stack.h"

typedef struct i_list
{
	char			*data;
	struct i_list	*next;
}	t_ins;

int		main(int argc, char **argv);
bool	is_sort(t_list *ref);
char	*read_instruction(int fd, t_list *stack);
void	free_er(char *str1, char *str2, t_list *stack);

#endif
