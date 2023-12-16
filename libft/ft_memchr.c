/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:49:55 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 12:31:19 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//function locates the first occurrence of c (converted to an
//unsigned char) in string s.
//returns a pointer to the byte located, or NULL if
//no such byte exists within n bytes.
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*su;

	uc = (unsigned char)c;
	su = (unsigned char *)s;
	while (n > 0)
	{
		if (*su == uc)
			return ((void *)su);
		++su;
		n--;
	}
	return (NULL);
}
// int	main(void)
// {
// //	char	str[20] = "Phanuwat";
// 	char	str[20] = "\0";
// 	//char	str[20] = "test\200";
// 	char	c = 't';
// 	size_t	n = 3;

// 	c = '\0';
// 	// c = 'a';
// 	//printf("%s", (char *)memchr(str, c, n));
// 	printf("%s", (char *)ft_memchr(str, c, n));
// }
