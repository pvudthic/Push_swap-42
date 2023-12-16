/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:54:40 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 13:37:58 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// char	f(unsigned int n, char c)
// {
// 	char a = 'a';
// 	return a;
// }
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*temp;

	i = 0;
	if (f == NULL || s == NULL)
		return (NULL);
	temp = ft_strdup(s);
	if (temp == NULL)
		return (NULL);
	while (temp[i] != '\0')
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	return (temp);
}
// int	main(void)
// {
// 	char	str[50] = "Phanuwat Vudthichai";

// 	printf("%s", ft_strmapi(str, &f));
// 	return (0);
// }
