/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_X.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:00:54 by jkim              #+#    #+#             */
/*   Updated: 2025/06/12 20:22:36 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	put_hex_upper(unsigned int n)
{
	char	c;

	if (n < 10)
		c = '0' + n;
	else
		c = 'A' + (n - 10);
	return (write(1, &c, 1));
}

int	print_bx(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += print_bx(n / 16);
	count += put_hex_upper(n % 16);
	return (count);
}
