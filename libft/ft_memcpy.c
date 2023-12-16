/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:53:43 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 12:42:43 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cvt_dst;
	const unsigned char	*cvt_src;
	size_t				i;

	cvt_dst = (unsigned char *)dst;
	cvt_src = (const unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		cvt_dst[i] = cvt_src[i];
		i++;
	}
	dst = cvt_dst;
	return (dst);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char s[] = "Hello";
// 	printf("%s\n", s);
// 	char *dest = &s[1];
// 	char *src = &s[0];
// 	printf("%s\n" ,ft_memcpy((void *)0, (void *)0, 5));
// 	printf("%s\n" , memcpy((void *)0, (void *)0, 5));
// 	// ft_memmove(dest, src, 5);
// 	printf("%s", s);
// }
