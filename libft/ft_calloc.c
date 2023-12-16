/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:49:35 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/19 14:35:18 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	t_size;
	size_t	max;
	void	*temp;

	max = SIZE_MAX;
	if (count == 0 | size == 0)
	{
		temp = malloc(0);
		return (temp);
	}
	if (count == INT_MAX && size == INT_MAX)
		return (NULL);
	t_size = count * size;
	if (count > (max / size))
		return (NULL);
	temp = malloc(t_size);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, count * size);
	return (temp);
}
// int	main(void)
// {
// 	char	*test;
// 	//int	count = 42;
// 	size_t	size = -1;
// 	int	i = 0;
// 	size_t	count = -1;

// 	// if use for char
// 	// int	count = 42;
// 	// int	size = 1;
// 	// int	i = 0;
// 	// test = (char *)ft_calloc(-1, -1);
// 	// if (test == NULL)
// 	// {
// 	// 	printf("Allocate failed");
// 	// 	return (0);
// 	// }
// 	// while (count > 0)
// 	// {
// 	// 	printf("%02x ", test[i]);
// 	// 	count--;
// 	// 	i++;

// 	// }
// 	//free(test);

// 	size_t max;
// 	max = -1;
// 	count = 2;
// 	size = max / 2 + 2;
// 	printf("%llu %llu\n", size, size * count);
// 	test = calloc(count, size);
// 	printf("%p\n", test);
// 	free(test);
// 	test = ft_calloc(count, size);
// 	printf("%p\n", test);
// 	free(test);

// 	return 0;
// }
