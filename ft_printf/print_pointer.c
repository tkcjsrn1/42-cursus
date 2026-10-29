/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:50:58 by jkim              #+#    #+#             */
/*   Updated: 2025/06/13 16:14:32 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	print_hex_rsv(uintptr_t digit) // rev = recervise
{
	char	c;

	if (digit < 10)
		c = '0' + digit;
	else
		c = 'a' + (digit - 10);
	return (write(1, &c, 1));
}

static int	print_hex_recursive(uintptr_t n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += print_hex_recursive(n / 16);
	count += print_hex_rsv(n % 16);
	return (count);
}

int	print_pointer(void *ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	count += print_hex_recursive((uintptr_t)ptr);
	return (count);
}
