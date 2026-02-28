/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:34:05 by elewin            #+#    #+#             */
/*   Updated: 2025/12/01 16:39:13 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign_flag;
	int	res;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign_flag = 0;
	if (nptr[i] == '-')
	{
		sign_flag = 1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	res = 0;
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	if (sign_flag)
		return (-res);
	return (res);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	else if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}
