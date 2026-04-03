/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:44:49 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:20:24 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	character;
	size_t	len;

	len = ft_strlen(s);
	character = (char)c;
	if (!c)
		return ((char *)&s[len]);
	i = len - 1;
	while (i >= 0)
	{
		if (s[i] == character)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
