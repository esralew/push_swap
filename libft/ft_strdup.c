/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:28:24 by elewin            #+#    #+#             */
/*   Updated: 2025/12/03 19:25:43 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*new_str;

	len_s = ft_strlen(s);
	new_str = (char *)malloc(len_s + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, len_s + 1);
	return (new_str);
}
