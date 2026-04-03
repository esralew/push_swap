/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:48:00 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:19:01 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		character;
	size_t		i;
	const char	*string;

	character = (char)c;
	string = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (string[i] == character)
			return ((void *)&string[i]);
		i++;
	}
	return (NULL);
}
