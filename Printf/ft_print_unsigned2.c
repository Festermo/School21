/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:04:48 by festermo          #+#    #+#             */
/*   Updated: 2020/07/02 15:20:44 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_wsl_uns(char *flags, int *length, int numb, char *symb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > ft_count_digits(numb))
		{
			i++;
			write(1, " ", 1);
		}
		i += ft_count_digits(numb);
		ft_putnbr_fd_unsigned(numb, 1);
	}
	else
	{
		ft_putnbr_fd_unsigned(numb, 1);
		i += ft_count_digits(numb);
		while ((*length)-- > ft_count_digits(numb))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}

int		ft_wz_unsg(char *flags, char *symb, int *length, int numb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > ft_count_digits(numb))
		{
			i++;
			write(1, &*symb, 1);
		}
		i += ft_count_digits(numb);
		ft_putnbr_fd_unsigned(numb, 1);
	}
	else
	{
		ft_putnbr_fd_unsigned(numb, 1);
		i += ft_count_digits(numb);
		while ((*length)-- > ft_count_digits(numb))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}
