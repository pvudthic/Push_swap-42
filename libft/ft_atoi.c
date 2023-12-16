/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:49:11 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/19 14:28:51 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_long_long(long long res, char str, int n)
{
	if (n > 0)
	{
		if (res == LLONG_MAX / 10 && (str - '0') > LLONG_MAX % 10)
		{
			return (-1);
		}
		else if (res > LLONG_MAX / 10)
		{
			return (-1);
		}
	}
	else if (n < 0)
	{
		if (res == LLONG_MIN / 10 && (str - '0') > (LLONG_MIN % 10) * (-1))
		{
			return (0);
		}
		else if (res < LLONG_MIN / 10)
		{
			return (0);
		}
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			n;
	long long	res;
	int			check;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = check_long_long(res, str[i], n);
		if (check == -1 || check == 0)
			return (check);
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return ((int)res * n);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d",ft_atoi("--1"));
// }
