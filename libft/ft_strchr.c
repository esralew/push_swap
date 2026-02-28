/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:01:44 by elewin            #+#    #+#             */
/*   Updated: 2025/11/29 14:38:03 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	character;
	size_t	len;

	len = ft_strlen(s);
	character = (char)c;
	if (!c)
		return ((char *)&s[len]);
	i = 0;
	while (i < len)
	{
		if (s[i] == character)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
