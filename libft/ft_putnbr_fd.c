/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:55:17 by elewin            #+#    #+#             */
/*   Updated: 2025/12/05 15:19:26 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_pos_nbr(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		put_pos_nbr(-n, fd);
		return ;
	}
	else
	{
		put_pos_nbr(n, fd);
		return ;
	}
}

static void	put_pos_nbr(int n, int fd)
{
	char	digit;

	if (n == 0)
		return ;
	put_pos_nbr(n / 10, fd);
	digit = (n % 10) + 48;
	write(fd, &digit, 1);
	return ;
}
