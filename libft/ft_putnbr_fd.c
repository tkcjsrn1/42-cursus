/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim <jkim@42tokyo.jp>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:34:04 by jkim              #+#    #+#             */
/*   Updated: 2025/05/13 14:54:59 by jkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		un = (unsigned int)(-n);
	}
	else
		un = (unsigned int)n;
	if (un >= 10)
		ft_putnbr_fd (un / 10, fd);
	c = (un % 10) + '0';
	write (fd, &c, 1);
}
