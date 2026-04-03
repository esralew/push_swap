/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:38:42 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:17:19 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}

int	print_str(va_list args)
{
	char	*string;

	string = va_arg(args, char *);
	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}

int	print_int(va_list args)
{
	int	num;
	int	bytes_printed;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
	bytes_printed = 0;
	if (num <= 0)
		bytes_printed++;
	while (num != 0)
	{
		num /= 10;
		bytes_printed++;
	}
	return (bytes_printed);
}

int	print_uint(va_list args)
{
	unsigned int	num;
	int				bytes_printed;

	num = va_arg(args, unsigned int);
	if (num == 0)
		ft_putnbr_fd(0, 1);
	ft_put_large_nbr((unsigned long int)num);
	bytes_printed = 0;
	if (num <= 0)
		bytes_printed++;
	while (num != 0)
	{
		num /= 10;
		bytes_printed++;
	}
	return (bytes_printed);
}

int	print_pointer(va_list args, char specifier)
{
	unsigned long int	address;
	int					bytes_printed;

	address = (unsigned long int)va_arg(args, void *);
	if (address == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_put_large_nbr_hex(address, specifier);
	bytes_printed = 0;
	if (address <= 0)
		bytes_printed++;
	while (address != 0)
	{
		address /= 16;
		bytes_printed++;
	}
	return (bytes_printed + 2);
}
