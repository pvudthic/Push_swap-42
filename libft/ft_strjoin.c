/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:54:19 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 15:27:19 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*check_s(char const *s1, char const *s2)
{
	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*temp;
	size_t		size_s1;
	size_t		size_s2;
	char const	*s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s = check_s(s1, s2);
	if (s1 != NULL && s2 != NULL)
	{
		size_s1 = ft_strlen(s1);
		size_s2 = ft_strlen(s2);
		temp = (char *)malloc(((size_s1) + (size_s2) + 1));
		if (temp == NULL)
			return (NULL);
		ft_memmove(temp, s1, size_s1);
		ft_memmove(temp + size_s1, s2, size_s2);
		temp[size_s1 + size_s2] = '\0';
		return (temp);
	}
	temp = ft_strdup(s);
	if (temp == NULL)
		return (NULL);
	return (temp);
}
//Notes
//size_s1 + 1 Why + 1 ? Because if s1 is empty string
//we should + 1 for NULL Terminator
// int	main(void)
// {
// 	char	str1[20] = "";
// 	char	str2[20] = "";
// 	char	*joined_str;
// 	joined_str = ft_strjoin(str1, str2);
// 	ft_strjoin("abc", "");
// 	printf("output : %s\n", joined_str);
// 	printf("%02x ", joined_str[0]);
// 	printf("%02x ", joined_str[1]);
// 	printf("%02x", joined_str[2]);
// 	free(joined_str);
// 	return (0);
// }
