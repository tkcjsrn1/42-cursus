/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:52:15 by jkim              #+#    #+#             */
/*   Updated: 2025/05/04 02:13:55 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *a, const char *b, size_t c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (ft_strlen(b));
	while (i < c - 1 && b[i] != '\0')
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
	return (ft_strlen(b));
}
/*
int main()
{
	char dst[5];
	size_t ret;

	ret = ft_strlcpy(dst, "hello", 5);

	printf("%s\n", dst);
	printf("%zu", ret);
}
*/
