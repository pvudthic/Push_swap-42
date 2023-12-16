/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:55:05 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 15:27:20 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*new_str;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1) -1;
	while (start <= end && ft_strchr(set, *start))
		start++;
	while (start <= end && ft_strchr(set, *end))
		end--;
	new_str = malloc(sizeof(char) * (end - start + 1) + 1);
	if (new_str == NULL)
		return (NULL);
	len = end - start + 1;
	ft_memcpy(new_str, start, len);
	new_str[end - start + 1] = '\0';
	return (new_str);
}
//We should +1 on (end - start ) becuase it total length of string
//(end - start) is difference between address
//such ass 3 4 5 6 7  8 -> difference is 8 - 3 = 5
//but total character (length) is 6 so it 5 + 1 = 6
//There for : we should (end - start + 1) for total length of string
//And +1 for NULL Terminator
// int	main(void)
// {
// 	char	str1[20] = " Phanuwat a  ";
// 	char	str2[20] = "P ";
// 	char	*trim_str;
// 	char	*trim_str2;

// 	printf("%ld\n", strlen("hanuwat a"));
// 	trim_str = ft_strtrim(str1, str2);
// 	trim_str2 = ft_strtrim("ab cd  f    ", " ");
// 	printf("output : %s\n", trim_str);
// 	printf("output : %s\n", trim_str2);
// 	// printf("%02x ", trim_str[0]);
// 	// printf("%02x ", trim_str[1]);
// 	// printf("%02x", trim_str[2]);
// 	free(trim_str);
// 	return (0);
// }
