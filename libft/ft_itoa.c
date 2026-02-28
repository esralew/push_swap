/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:29:20 by elewin            #+#    #+#             */
/*   Updated: 2025/12/08 16:06:50 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long nbr);
static void	fill_buf(long nbr, int digits, char *buf);
static void	fill_neg_buf(long nbr, int digits, char *buf);

char	*ft_itoa(int n)
{
	char	*buf;
	int		digits;
	long	nbr;

	nbr = (long)n;
	digits = count_digits(nbr);
	buf = (char *)malloc(digits + 1);
	if (!buf)
		return (NULL);
	buf[digits] = '\0';
	if (nbr < 0)
	{
		fill_neg_buf(-nbr, digits, buf);
		buf[0] = '-';
	}
	if (nbr != 0)
		fill_buf(nbr, digits, buf);
	else
		buf[0] = '0';
	return (buf);
}

static int	count_digits(long nbr)
{
	int	digits;

	digits = 0;
	if (nbr <= 0)
		digits++;
	while (nbr != 0)
	{
		digits++;
		nbr /= 10;
	}
	return (digits);
}

static void	fill_buf(long nbr, int digits, char *buf)
{
	if (digits == 0)
		return ;
	fill_buf(nbr / 10, digits - 1, buf);
	buf[digits - 1] = (nbr % 10) + '0';
	return ;
}

static void	fill_neg_buf(long nbr, int digits, char *buf)
{
	if (digits == 0)
		return ;
	fill_buf(nbr / 10, digits - 1, buf);
	buf[digits - 1] = (nbr % 10) + '0';
	return ;
}

/*
#include <stdio.h>

int	main(void)
{
		char    *buf;
		int	num;

		num = 2147483647;
		buf = ft_itoa(num);
		printf("terminator: %d\n", buf[count_digits(num)]);
		printf("%s\n", buf);
		return (0);
}
*/
