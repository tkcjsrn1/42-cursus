/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:14:04 by jkim              #+#    #+#             */
/*   Updated: 2025/06/12 20:11:33 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	put_digit(unsigned int n)
{
	char	c;

	c = '0' + n;
	return (write(1, &c, 1));
}

static int	print_unsigned_recursive(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_unsigned_recursive(n / 10);
	count += put_digit(n % 10);
	return (count);
}

int	print_unsigned(unsigned int n)
{
	return (print_unsigned_recursive(n));
}
