/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:48:58 by jkim              #+#    #+#             */
/*   Updated: 2025/07/30 18:25:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	frees(char **res, size_t i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

static int	split_word(char const **s, char c, char **dst)
{
	size_t	len;

	len = word_len(*s, c);
	*dst = ft_substr(*s, 0, len);
	if (!*dst)
		return (-1);
	*s += len;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (split_word(&s, c, &res[i]) == -1)
				return (frees(res, i), NULL);
			i++;
		}
	}
	return (res[i] = NULL, res);
}
