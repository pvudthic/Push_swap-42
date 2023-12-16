/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:16:38 by pvudthic          #+#    #+#             */
/*   Updated: 2023/11/07 16:16:39 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnb_hex(unsigned long addr, char format, ssize_t byte, int check)
{
	if (check == -1)
		return (-1);
	if (addr > 15)
	{
		byte += ft_putnb_hex(addr / 16, format, byte, 1);
		if (byte == -1)
			return (-1);
	}
	if (format == 'x')
		check = write(1, &"0123456789abcdef"[addr % 16], 1);
	else if (format == 'X')
		check = write(1, &"0123456789ABCDEF"[addr % 16], 1);
	if (check == -1)
		return (-1);
	byte += 1;
	return (byte);
}

ssize_t	ft_putnb_addr(unsigned long addr, ssize_t byte, int check)
{
	if (check == -1)
		return (-1);
	if (addr > 15)
		byte += ft_putnb_addr(addr / 16, byte, 1);
	check = write(1, &"0123456789abcdef"[addr % 16], 1);
	if (check == -1)
		return (-1);
	byte += 1;
	return (byte);
}

ssize_t	ft_putaddr(unsigned long addr, ssize_t byte)
{
	if (addr == 0)
		return (write(1, "0x0", 3));
	else if (ft_putstr("0x") == -1)
		return (-1);
	byte = ft_putnb_addr(addr, 0, 0);
	if (byte != -1)
		byte += 2;
	return (byte);
}

ssize_t	ft_putnbr_signed(int n, ssize_t byte, int check)
{
	char	x;

	if (check == -1)
		return (-1);
	if (n < 0 && n > -10)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		byte++;
	}
	if (n >= 10 || n <= -10)
	{
		byte += ft_putnbr_signed(n / 10, byte, 1);
		if (byte == -1)
			return (-1);
		n %= 10;
	}
	if (n >= 0)
		x = '0' + n;
	else
		x = '0' - n;
	if (write(1, &x, 1) == -1)
		return (-1);
	byte++;
	return (byte);
}

ssize_t	ft_putnbr_unsigned(unsigned int n, ssize_t byte, int check)
{
	char	x;

	if (check == -1)
		return (-1);
	if (n >= 10)
	{
		byte += ft_putnbr_unsigned(n / 10, byte, 0);
		if (byte == -1)
			return (-1);
		n %= 10;
	}
	if (n >= 0)
		x = '0' + n;
	else
		x = '0' - n;
	if (write(1, &x, 1) == -1)
		return (-1);
	byte++;
	return (byte);
}
