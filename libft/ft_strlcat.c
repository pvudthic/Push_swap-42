/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:25:25 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/19 14:57:01 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	i;

	if (dest == NULL && size == 0)
		return (0);
	dest_len = 0;
	src_len = 0;
	total_len = 0;
	i = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	total_len = dest_len + src_len;
	if (dest_len >= size)
		return (total_len);
	while (src[i] != '\0' && (dest_len + i) < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (total_len);
}
// int	main(void)
// {
// 	char	dest[30] = "111111111100000000000000000000";
// 	char	*src = (char *)"AAAAAAAAA";
// 	//char dest2[10000] = "";
// 	char	dest2[30] = "111111111100000000000000000000";

// 	ft_memset(dest, 0, 30);
// 	ft_memset(dest, '1', 10);
// 	ft_memset(dest2, 0, 30);
// 	ft_memset(dest2, '1', 10);
// 	printf("%zu\n", ft_strlcat(dest, "", 15));
// 	printf("%zu\n", strlcat(dest2, "", 15));
// 	printf("%s\n", dest);
// 	printf("%s", dest2);
// }
