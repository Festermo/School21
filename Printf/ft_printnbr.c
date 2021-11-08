/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:25:40 by festermo          #+#    #+#             */
/*   Updated: 2020/07/02 16:02:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printnbr(int numb, char *flags, int *star, int *ret_val)
{
	char	symb;
	int		length;
	int		width;

	symb = '\0';
	length = 0;
	width = 0;
	flags = ft_length_init(flags, star, &length, &symb);
	ft_length_short(numb, &width, &length, ret_val);
	if (ft_strchr(flags, '.'))
	{
		ft_nbr_init_width(&width, star, flags);
		if (width == 0 && numb == 0)
			star[1] != 0 ? ft_hex_znazw(&length, ret_val, 1, numb) :
			(ft_hex_znazw(&length, ret_val, 0, numb));
		else if (numb == -2147483648)
			ft_minint(&width, &length, 2, ret_val);
		else if (width > count_tens(numb, if_negative(numb))
		+ if_negative(numb))
			*ret_val += ft_nbr_wblall(numb, width, length, flags);
		else
			*ret_val += ft_nbr_wslall(numb, width, length, flags);
	}
	else
		*ret_val += ft_nbr_wzall(flags, numb, length, symb);
}

void	ft_nbr_init_width(int *width, int *star, char *flags)
{
	int j;

	j = 0;
	if (star[1] == 0)
	{
		while (!ft_strchr(".", flags[j]))
			j++;
		j++;
		while (!ft_strchr("i", flags[j]) || !ft_strchr("d", flags[j]))
		{
			*width = *width * 10 + (flags[j] - '0');
			j++;
		}
	}
	else if (star[1] < 0)
		*width = 0;
	else
		*width = star[1];
}

int		ft_wbl1_nbr(int numb, int *length, int *width)
{
	int i;

	i = 0;
	while ((*length)-- - *width > 0)
	{
		i++;
		write(1, " ", 1);
	}
	while ((*width)-- > count_tens(numb, if_negative(numb)) + if_negative(numb))
	{
		i++;
		write(1, "0", 1);
	}
	i += count_tens(numb, if_negative(numb)) + if_negative(numb);
	ft_putnbr_fd_long(numb, 1);
	return (i);
}

int		ft_wbl2_nbr(int numb, int *length, int *width)
{
	int i;

	i = 0;
	numb = numb * -1;
	while ((*length)-- - *width > 1)
	{
		i++;
		write(1, " ", 1);
	}
	write(1, "-", 1);
	i++;
	while ((*width)-- > count_tens(numb, if_negative(numb)) + if_negative(numb))
	{
		i++;
		write(1, "0", 1);
	}
	i += count_tens(numb, if_negative(numb)) + if_negative(numb);
	ft_putnbr_fd_long(numb, 1);
	return (i);
}

int		ft_wbl3_nbr(int numb, char *flags, int *length, int *width)
{
	int		i;
	int		buf;
	char	symb;

	symb = ' ';
	if (ft_strchr("0", *flags))
		symb = '0';
	i = 0;
	buf = *width;
	while ((*width)-- > count_tens(numb, if_negative(numb)) + if_negative(numb))
	{
		i++;
		write(1, "0", 1);
	}
	i += count_tens(numb, if_negative(numb)) + if_negative(numb);
	ft_putnbr_fd_long(numb, 1);
	while ((*length)-- - buf > 0)
	{
		i++;
		write(1, &symb, 1);
	}
	return (i);
}
