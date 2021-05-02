/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:31:27 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/23 13:25:25 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

size_t	ft_wordlen(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**free_res(char **res, size_t col_nw)
{
	size_t	j;

	j = 0;
	while (j < col_nw)
	{
		free((char *)res[j]);
		j++;
	}
	free(res);
	res = NULL;
	return (NULL);
}

size_t	count_i(char const *s, char c, size_t i)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!res)
		return (NULL);
	while (j < words(s, c))
	{
		i = count_i(s, c, i);
		res[j] = ft_substr(s, i, ft_wordlen(&(s[i]), c));
		if (!res[j])
		{
			free_res(res, j);
			return (NULL);
		}
		i += ft_wordlen(&(s[i]), c);
		j++;
	}
	res[j] = NULL;
	return (res);
}
