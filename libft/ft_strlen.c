/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:54:33 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/02 15:54:35 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
// int	main(void)
// {
// 	char	str[9] = "Phanuwat";
// 	printf("%zu\n", ft_strlen(str + 10));
// 	printf("%zu", strlen(str + 10));
// 	return 0;
// }
