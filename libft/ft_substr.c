/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:55:08 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 14:20:08 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_space(unsigned int start, size_t len, size_t len_s)
{
	size_t	space_substr;

	if (len > len_s - start)
		space_substr = len_s - start;
	else
		space_substr = len;
	return (space_substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	size_t	space_substr;
	char	*temp;

	i = 0;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s || len_s == 0 || len == 0)
	{
		temp = ft_strdup("");
		if (temp == NULL)
			return (NULL);
	}
	else
	{
		space_substr = check_space(start, len, len_s);
		temp = (char *)ft_calloc((space_substr + 1), sizeof(char));
		if (temp == NULL)
			return (NULL);
		while (i < space_substr)
			temp[i++] = s[start++];
	}
	return (temp);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	str[20] = "Phanuwat";
// 	size_t	size = 10;
// 	size_t	zero = 0;
// 	//char	*sub_str;
// 	char	*sub_str;

// 	//sub_str = ft_substr(str, 10, size);
// 	printf("%s",ft_substr("",0,0));
// 	sub_str = ft_substr("", 10, 0);
// 	printf("%s\n", sub_str);
// 	sub_str = ft_substr("", 10, size);
// 	printf("%s\n", sub_str);
// 	sub_str = ft_substr("Phanuwat", 3, size);
// 	printf("%s\n", sub_str);
// 	sub_str = ft_substr(str, 0, strlen(str));
// 	printf("%s\n", sub_str);
// 	sub_str = ft_substr("hola", 0, SIZE_MAX);
// 	printf("%s", sub_str);
// 	free(sub_str);
// }
