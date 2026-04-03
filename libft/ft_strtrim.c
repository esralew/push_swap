/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:20:35 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:20:28 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	trimmed_len;

	if (!s1)
		return (ft_substr(s1, 0, 0));
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	if (!s1[i])
		return (ft_substr(s1, 0, 0));
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[j]))
		j--;
	trimmed_len = j - i + 1;
	return (ft_substr(s1, i, trimmed_len));
}
