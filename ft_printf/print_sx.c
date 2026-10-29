/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:57:08 by jkim              #+#    #+#             */
/*   Updated: 2025/06/13 16:27:26 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	put_hex_digit(unsigned int n)
{
	char	c;

	if (n < 10)
		c = '0' + n;
	else
		c = 'a' + (n - 10);
	return (write(1, &c, 1));
}

int	print_x(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += print_x(n / 16);
	count += put_hex_digit(n % 16);
	return (count);
}
