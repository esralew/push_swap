/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:48:08 by elewin            #+#    #+#             */
/*   Updated: 2025/12/03 19:10:49 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	if (!n)
		return (0);
	i = 0;
	while (i < (n - 1) && string1[i] == string2[i])
		i++;
	return (string1[i] - string2[i]);
}
