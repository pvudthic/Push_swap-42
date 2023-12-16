/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maramick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:16:11 by pvudthic          #+#    #+#             */
/*   Updated: 2023/12/16 17:32:15 by maramick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

ssize_t	ft_putchar(char *c);
ssize_t	ft_putnb_hex(unsigned long addr, char format, ssize_t byte, int check);
ssize_t	ft_putnbr_unsigned(unsigned int n, ssize_t byte, int check);
ssize_t	ft_putnbr_signed(int n, ssize_t byte, int check);
ssize_t	ft_putaddr(unsigned long addr, ssize_t byte);
ssize_t	ft_putstr(char *s);
ssize_t	ft_put_format(const char *format, va_list ptr);
int		ft_printf(const char *format, ...);

#endif
