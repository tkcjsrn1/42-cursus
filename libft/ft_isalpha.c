/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:36:14 by jkim              #+#    #+#             */
/*   Updated: 2025/05/06 18:13:24 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	int	answer;

	answer = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		answer = 1;
	return (answer);
}

//int main ()
//{	char sd = 'z';
//	printf("%d",ft_isalpha(sd));
//	return (0);
//}
