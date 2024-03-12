/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:23:35 by pvudthic          #+#    #+#             */
/*   Updated: 2024/03/12 13:23:36 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	is_sort(t_list *ref)
{
	t_stack	*current;

	if (ref->b)
		return (false);
	current = ref->a;
	while (current->next != NULL)
	{
		if ((current->nb > current->next->nb))
			return (false);
		current = current->next;
	}
	return (true);
}

char	*read_instruction(int fd, t_list *stack)
{
	int		rd;
	char	*buf;
	char	*old_data;
	char	*data;

	data = NULL;
	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
		free_er(NA, NA, stack);
	rd = 1;
	while (rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			free_er(buf, data, stack);
		buf[rd] = 0;
		old_data = data;
		data = ft_strjoin(data, buf);
		if (!data)
			free_er(buf, data, stack);
		free(old_data);
	}
	free(buf);
	return (data);
}

void	free_er(char *str1, char *str2, t_list *stack)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	error_exit(stack);
}
