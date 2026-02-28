/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:07:54 by elewin            #+#    #+#             */
/*   Updated: 2025/12/12 13:12:17 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_count(char const *s, char c);
static size_t	get_word_len(char const *s, char c);
static void		*free_and_return(char **arr, size_t j);
static char		**fill_arr(char **arr, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = get_word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (NULL);
	arr[word_count] = NULL;
	if (word_count == 0)
		return (arr);
	return (fill_arr(arr, s, c));
}

static char	**fill_arr(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			arr[j] = ft_substr(s, i, get_word_len(&s[i], c));
			if (!(arr[j]))
				return (free_and_return(arr, j));
			j++;
			i += get_word_len(&s[i], c);
		}
	}
	return (arr);
}

static size_t	get_word_count(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word_count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	*free_and_return(char **arr, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
