/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:25:25 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 18:14:16 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c);

long	ft_strtol(const char *nptr)
{
	int		i;
	int		sign_flag;
	long	res;

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
