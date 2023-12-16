/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:49:03 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 12:47:48 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*convt;
	size_t			i;

	i = 0;
	convt = (unsigned char *)b;
	while (i < len)
	{
		convt[i] = (unsigned char)c;
		i++;
	}
	b = convt;
	return (b);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[50] = "Phanuwat Vudthichairangsun";
// 	char	str1[50] = "Phanuwat Vudthichairangsun";
// 	int c = -150;
// 	size_t	len = 10;

// 	printf("[ft_memset] before memset : %s\n", str);
// 	printf("[memset] before memset : %s\n", str1);
// 	ft_memset(str, c, len);
// 	memset(str1, c, len);
// 	printf("[ft_memset] after memset : %s\n", str);
// 	printf("[memset] 	after memset : %s", str1);
// }
