/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:27:36 by elewin            #+#    #+#             */
/*   Updated: 2025/12/12 13:07:41 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little || !big)
		return (NULL);
	if (!(*little))
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && (i + j) < len)
			j++;
		if (j == ft_strlen(little))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	char	*big;
	char	*little;
	size_t	len;
	char	*output;

	big = "lorem ipsum dolor sit amet";
	little = "ipsumm";
	len = 30;
	output = ft_strnstr(big, little, len);
	printf("%s\n", output);
	return (0);
}
*/
