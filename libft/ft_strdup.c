/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 04:58:50 by jkim              #+#    #+#             */
/*   Updated: 2025/05/13 21:14:57 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	size_t	i;

	len = 0;
	while (s[len])
		len ++;
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = s[i];
	return (copy);
}
/*
int main(void)
{
    char *s = ft_strdup("test");
    if (!s)
        return (1);
    printf("%s\n", s);
    free(s);
    return (0);
}
*/
