/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:33:50 by jkim              #+#    #+#             */
/*   Updated: 2025/06/17 02:44:36 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;

	total_len = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			total_len += ft_format(args, *format);
		}
		else
			total_len += write(1, format, 1);
		format++;
	}
	va_end (args);
	return (total_len);
}
