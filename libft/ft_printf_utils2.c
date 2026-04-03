/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:39:00 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:17:28 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_hex(va_list args, char specifier)
{
	unsigned long int	hex_num;
	int					bytes_printed;

	hex_num = (unsigned long int)va_arg(args, unsigned int);
	if (hex_num == 0)
		ft_putnbr_fd(0, 1);
	ft_put_large_nbr_hex(hex_num, specifier);
	bytes_printed = 0;
	if (hex_num <= 0)
		bytes_printed++;
	while (hex_num != 0)
	{
		hex_num /= 16;
		bytes_printed++;
	}
	return (bytes_printed);
}

void	ft_put_large_nbr(unsigned long int n)
{
	char	digit;

	if (n == 0)
		return ;
	ft_put_large_nbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

void	ft_put_large_nbr_hex(unsigned long int n, char specifier)
{
	char	character;

	if (n == 0)
		return ;
	ft_put_large_nbr_hex(n / 16, specifier);
	if ((n % 16) > 9)
	{
		if (specifier == 'x' || specifier == 'p')
			character = (n % 16) + 87;
		else
			character = (n % 16) + 55;
	}
	else
		character = (n % 16) + '0';
	write(1, &character, 1);
}
