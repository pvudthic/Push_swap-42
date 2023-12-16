/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maramick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:54:50 by pvudthic          #+#    #+#             */
/*   Updated: 2023/12/16 16:45:41 by maramick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while ((*s1 != '\0' || *s2 != '\0') && count != n)
	{
		if (*s1 != *s2)
		{
			return ((int)((unsigned char)*s1) - (int)((unsigned char)*s2));
		}
		s1++;
		s2++;
		count++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char a[] = " ";
//     char b[] = " __";
//     int n;

//     n = 200;
//     printf("%d", strncmp(a, b, 1));
//     printf("\n");

//     printf("%d", ft_strncmp(a, b, 1));
// }
