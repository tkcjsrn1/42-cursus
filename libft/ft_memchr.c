/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:17:28 by jkim              #+#    #+#             */
/*   Updated: 2025/05/13 20:35:17 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*p;
	size_t					i;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/*
int main()
{
    char *p = (char *)ft_memchr("abcde", 'c', 5);
    if (p)
        printf("%s\n", p);
    return 0;
}
*/
