/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:09:01 by jkim              #+#    #+#             */
/*   Updated: 2025/06/13 16:22:50 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char spec)
{
	if (spec == 'c')
		return (print_char(va_arg(args, int)));
	else if (spec == 's')
		return (print_str(va_arg(args, char *)));
	else if (spec == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (print_int(va_arg(args, int)));
	else if (spec == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (print_x(va_arg(args, unsigned int)));
	else if (spec == 'X')
		return (print_bx(va_arg(args, unsigned int)));
	else if (spec == '%')
		return (print_percent());
	return (0);
}
