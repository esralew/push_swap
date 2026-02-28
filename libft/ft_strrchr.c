/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:44:49 by elewin            #+#    #+#             */
/*   Updated: 2025/11/28 18:28:53 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
