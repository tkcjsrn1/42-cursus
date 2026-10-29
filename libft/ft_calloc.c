/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:57:14 by jkim              #+#    #+#             */
/*   Updated: 2025/05/13 21:10:38 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdint.h>
//#include <stdio.h>

void	*ft_calloc(size_t c, size_t s)
{
	void	*p;

	if (s != 0 && c > SIZE_MAX / s)
		return (NULL);
	p = malloc(c * s);
	if (!p)
		return (NULL);
	ft_bzero(p, c * s);
	return (p);
}
/*
int main(void)
{
    unsigned char *p = ft_calloc(3, 1);
    if (!p)
        return (1);
    printf("%d %d %d\n", p[0], p[1], p[2]);
    free(p);
    return (0);
}
*/
