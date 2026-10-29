/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 04:56:52 by jkim              #+#    #+#             */
/*   Updated: 2025/05/14 02:54:41 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (!hay && n == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)hay);
	i = 0;
	while (hay[i] && i < n)
	{
		j = 0;
		while (needle[j] && hay[i + j] == needle[j] && (i + j) < n)
			j++;
		if (needle[j] == '\0')
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}
/*
int main()
{
	printf("%s\n", ft_strnstr("jeong hyeok", "hye", 12));
	return (0);
}
*/
