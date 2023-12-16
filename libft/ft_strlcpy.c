/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:54:28 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/19 14:36:12 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	while (src[count] != '\0' && count < dstsize)
	{
		dst[count] = src[count];
		count++;
	}
	if (dstsize > count)
		dst[count] = '\0';
	else if (dstsize != 0)
		dst[count - 1] = '\0';
	while (src[count] != '\0')
		count++;
	return (count);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char des[10] = "AAAAAAAAAA";
// 	int	n;
// 	n = 15;
// 	// printf("%zu\n", ft_strlcpy(des, "", n));
// 	// printf("%s", des);
// 	printf("%zu\n", strlcpy(des, "", n));
// 	printf("%s", des);
// }
