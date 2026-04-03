/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:22:32 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:20:30 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	buf_size;
	size_t	strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
	{
		buf = (char *)malloc(1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
		return (buf);
	}
	if (len > strlen - start)
		len = strlen - start;
	buf_size = len + 1;
	buf = (char *)malloc(buf_size);
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, &s[start], buf_size);
	return (buf);
}
