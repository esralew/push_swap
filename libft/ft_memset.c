/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:12:46 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:19:27 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*start;

	start = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		start[i] = c;
		i++;
	}
	return (s);
}
