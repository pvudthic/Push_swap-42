/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:53:47 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 12:46:15 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cvt_dst;
	const char	*cvt_src;

	cvt_src = (const char *)src;
	cvt_dst = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src && dst < src + len)
	{
		cvt_src = cvt_src + len;
		cvt_dst = cvt_dst + len;
		while (len-- > 0)
			*(--cvt_dst) = *(--cvt_src);
	}
	else
	{
		while (len-- > 0)
			*(cvt_dst++) = *(cvt_src++);
	}
	return (dst);
}
//Use if (dst == NULL && src == NULL)
//For prevent copy NULL address and avoid dereferencing NULL pointers
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int	main(void)
// {
// 	char	src1[20] = "Hello, world!";
// 	char	src2[20] = "Hello, world!";
// 	char	dest1[20];
// 	char	dest2[20];
// 	printf("--Before copy:--\n");
// 	printf("Source1:			%s\n", src1);
// 	printf("Source2:			%s\n", src2);
// 	memmove(src1 + 2, src1 + 1, 6);
// 	memmove(dest1, src1 + 1, 6);
// 	ft_memmove(src2 + 2, src2 + 1, 6);
// 	ft_memmove(dest2, src2 + 1, 6);
// 	printf("\n--After copy:--\n");
// 	printf("Source1:			%s\n", src1);
// 	printf("dest1:			%s\n", dest1);
// 	printf("Source2:			%s\n", src2);
// 	printf("dest2:			%s\n", dest2);
// 	//exit(0);
// 	return (0);
// }
