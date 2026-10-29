/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:05:40 by jkim              #+#    #+#             */
/*   Updated: 2025/05/16 20:06:52 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
size_t	ft_strlcat(char *d, const char *s, size_t ds)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	while (d_len < ds && d[d_len])
		d_len++;
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (d_len >= ds)
		return (ds + s_len);
	i = 0;
	while (s[i] && d_len + i + 1 < ds)
	{
		d[d_len + i] = s[i];
		i++;
	}
	if (d_len + i < ds)
		d[d_len + i] = '\0';
	return (d_len + s_len);
}
/*
int main()
{
	char	dst[6] = "a";
	const char	*src = "b";
	size_t	result;

	result = ft_strlcat(dst, src, 6);
	printf("destionation : %s\n", dst);
	printf("ret : %zu\n", result);
}
*/
