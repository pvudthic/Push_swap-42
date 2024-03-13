/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:30:25 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 16:30:26 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "stack.h"
# include "inc_stdlib.h"

void	do_pa(t_list *stack);
void	do_pb(t_list *stack);
void	do_sa(t_list *stack);
void	do_sb(t_list *stack);
void	do_ss(t_list *stack);
void	do_ra(t_list *stack);
void	do_rb(t_list *stack);
void	do_rr(t_list *stack);
void	do_rra(t_list *stack);
void	do_rrb(t_list *stack);
void	do_rrr(t_list *stack);
int		show_output(char *str, int show);

#endif
