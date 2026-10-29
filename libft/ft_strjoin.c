/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:43:13 by jkim              #+#    #+#             */
/*   Updated: 2025/05/13 22:14:22 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	connecting(char *sum, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;

	len1 = ft_strlen(s1);
	i = 0;
	j = 0;
	while (i < len1)
		sum[i++] = s1[j++];
	j = 0;
	while (s2[j])
		sum[i++] = s2[j++];
	sum[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	sum = malloc(total + 1);
	if (!sum)
		return (NULL);
	connecting(sum, s1, s2);
	return (sum);
}
