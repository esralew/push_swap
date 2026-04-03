/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:28:24 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:19:56 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
