/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:49:59 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 12:34:39 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sc1;
	const unsigned char	*sc2;

	sc1 = (const unsigned char *)s1;
	sc2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*sc1 != *sc2)
			return (*sc1 - *sc2);
		++sc1;
		++sc2;
		n--;
	}
	return (0);
}
//Notes
//return first difference btye! not difference address
//Since memcmp doesn't require null-terminated strings,
//it can be used to compare non-string data
//(e.g., binary data, structs) without worrying about null terminators.
//strncmp is specifically designed for comparing C strings,
// so it relies on null terminators to determine
//the end of the strings.
// #include <stdio.h>
// int	main(void)
// {
//  	char *s1 = "\xff\xaa\xde\xffMACOSX\xff";
//  	char *s2 = "\xff\xaa\xde\x02";
//  	size_t size = 8;
//  	//int i1 = simple_memcmp(s1, s2, size);
//  	int i2 = ft_memcmp(s1, s2, size);
// 	printf("%d", i2);
// }
