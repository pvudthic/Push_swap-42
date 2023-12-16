/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:49:52 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 12:15:57 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0 || n < 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	recursive_value(char *temp, int n)
{
	char	x;

	temp--;
	if (n >= 10 || n <= -10)
	{
		recursive_value(temp, n / 10);
		n %= 10;
	}
	if (n >= 0)
	{
		x = '0' + n;
	}
	else
		x = '0' - n;
	*temp = x;
}

char	*ft_itoa(int n)
{
	int		count_d;
	char	*temp;
	char	*temp_start;

	count_d = count_digit(n);
	temp = (char *)ft_calloc(((n < 0) + count_d + 1), sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp_start = temp;
	if (n < 0)
	{
		*temp = '-';
		temp++;
	}
	temp = temp + count_d;
	recursive_value(temp, n);
	temp = temp_start;
	return (temp);
}

// int	main(void)
// {
// 	int	num;
// 	int	num2;
// 	int	num_max;
// 	int	zero;
// 	num = 0x2A;
// 	num2 = 42;
// 	zero = 0;
// 	//num_max = 2147483647;
// 	num_max = -2147483648;
// 	//Oserve this to binary number
// 	//So we use the ideal of computer see in memory
// 	//Such as
// 	//Address 1 : (Machine code ) 101010 -> 42 (integer) -> * in ascii
// 	//Address 2 : (Machine code ) 1000001 -> 65 (integer)/ -> A in ascii
// 	char *res = ft_itoa(num_max);
//     printf("%s",res);
// 	return (0);
// }
