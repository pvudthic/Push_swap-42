/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:15:59 by pvudthic          #+#    #+#             */
/*   Updated: 2023/11/07 16:16:02 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_(const char *format, va_list ptr)
{
	ssize_t	format_byte;
	ssize_t	total_byte;

	total_byte = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format_byte = ft_put_format(format, ptr);
			if (format_byte == -1)
				return (-1);
			total_byte += format_byte;
			format += 2;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			total_byte += 1;
			format += 1;
		}
	}
	return ((int)total_byte);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		ret;

	if (!format)
		return (-1);
	va_start(ptr, format);
	ret = printf_(format, ptr);
	va_end(ptr);
	return (ret);
}
