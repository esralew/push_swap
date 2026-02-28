/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:14:57 by elewin            #+#    #+#             */
/*   Updated: 2025/12/10 15:37:42 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;
	size_t	buf_size;

	if (!size || !nmemb)
		return (malloc(0));
	buf_size = nmemb * size;
	if (nmemb != buf_size / size)
		return (NULL);
	buf = malloc(buf_size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, buf_size);
	return (buf);
}
