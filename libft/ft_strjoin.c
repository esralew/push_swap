/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:34:24 by elewin            #+#    #+#             */
/*   Updated: 2025/11/29 13:33:53 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	buf_size;

	buf_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	buf = (char *)malloc(buf_size);
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s1, buf_size);
	ft_strlcat(buf, s2, buf_size);
	return (buf);
}
