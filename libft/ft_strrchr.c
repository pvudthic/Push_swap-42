/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:49:51 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 14:06:29 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	if (*temp == '\0' && (char)c != '\0')
		return (NULL);
	if ((char)c == '\0' || ((char)c == '\0' && *temp == '\0'))
		return ((char *)s + ft_strlen(s));
	i = ft_strlen(s);
	i--;
	while (s[i] != ((char)c) && (s + i) >= temp)
	{
		if (!s[i] || (s + i) == temp)
			return (NULL);
		i--;
	}
	return ((char *)(s + i));
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	//char	*str2 = "bonjour";
// 	char	*src = "\0";
// 	char	*src2 = "\0";
// 	//printf("%s", ft_strrchr(str2 + 2, 'n'));
// 	printf("%s\n", strrchr(src, 0));
// 	printf("%s", ft_strrchr(src2, 0));
// }
