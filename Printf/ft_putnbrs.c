/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:07:35 by festermo          #+#    #+#             */
/*   Updated: 2020/06/20 16:08:12 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_fd_long(long n, int fd)
{
	long i;

	i = n;
	if (i == -2147483648)
	{
		ft_putstr_fd("2147483648", fd);
		return ;
	}
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = -i;
	}
	if (i < 10)
	{
		ft_putchar_fd(i + '0', fd);
		return ;
	}
	ft_putnbr_fd(i / 10, fd);
	ft_putnbr_fd(i % 10, fd);
}

void	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	long long			mlt;
	int					digits;
	unsigned long long	now;
	int					buf;

	digits = 1;
	mlt = 1;
	now = n / 10;
	while (now != 0)
	{
		digits++;
		now /= 10;
	}
	buf = digits;
	while (digits > 1)
	{
		mlt *= 10;
		digits--;
	}
	while (buf-- > 0)
	{
		ft_putchar_fd(n / mlt + 48, fd);
		n %= mlt;
		mlt /= 10;
	}
}
