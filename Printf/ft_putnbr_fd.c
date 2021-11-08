/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:06:39 by festermo          #+#    #+#             */
/*   Updated: 2020/06/20 16:07:02 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int i;

	i = n;
	if (i == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
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
