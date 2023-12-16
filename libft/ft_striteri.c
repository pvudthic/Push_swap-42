/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:54:16 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 12:56:34 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// void	f(unsigned int n, char *c)
// {
// 	char a = 'a';
// 	*c = a;
// }
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
// int	main(void)
// {
// 	char	str[50] = "Phanuwat Vudthichai";

// 	printf("start : %s\n", str);
// 	ft_striteri(str, &f);
// 	printf("end : %s", str);
// 	return (0);
// }
