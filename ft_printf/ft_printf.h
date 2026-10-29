/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:45:28 by jkim              #+#    #+#             */
/*   Updated: 2025/09/01 15:54:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_format(va_list args, char spec);
int	print_char(char c);
int	print_str(char *s);
int	print_pointer(void *ptr);
int	print_int(int n);
int	print_unsigned(unsigned int n);
int	print_x(unsigned int n);
int	print_bx(unsigned int n);
int	print_percent(void);

#endif
