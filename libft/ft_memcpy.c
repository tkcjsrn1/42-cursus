/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 05:17:04 by jkim              #+#    #+#             */
/*   Updated: 2025/05/13 19:18:04 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t				i;
	unsigned char		*q;
	const unsigned char	*z;

	if (!d && !s)
		return (NULL);
	q = (unsigned char *)d;
	z = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		q[i] = z[i];
		i++;
	}
	return (d);
}
/*
int main()
{
	char src[] = "hello";
	char dst[10];
	
	ft_memcpy(dst, src, 6);
	printf("result : %s\n", dst);
}
*/
