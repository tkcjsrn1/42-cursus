/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:42:30 by jkim              #+#    #+#             */
/*   Updated: 2025/06/12 20:24:44 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	put_digit(int n)
{
	char	c;

	c = '0' + n;
	return (write(1, &c, 1));
}

static int	print_number(int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_number(n / 10);
	count += put_digit(n % 10);
	return (count);
}

int	print_int(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		count += write(1, "-", 1);
		count += write(1, "2", 1);
		count += print_number(147483648);
	}
	else
	{
		if (n < 0)
		{
			count += write(1, "-", 1);
			n = -n;
		}
		count += print_number(n);
	}
	return (count);
}
