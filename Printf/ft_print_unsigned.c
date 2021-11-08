/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:59:19 by festermo          #+#    #+#             */
/*   Updated: 2020/07/02 15:20:15 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_count_digits(unsigned int n)
{
	unsigned long long	now;
	int					digits;

	digits = 1;
	now = n / 10;
	while (now != 0)
	{
		digits++;
		now /= 10;
	}
	return (digits);
}

void	ft_print_unsigned(unsigned int numb, char *flags,
		int *star, int *ret_val)
{
	char	symb;
	int		width;
	int		length;

	symb = '\0';
	width = 0;
	length = 0;
	flags = ft_length_init(flags, star, &length, &symb);
	if (ft_strchr(flags, '.'))
	{
		ft_uns_init_width(&width, star, flags);
		if (width == 0 && numb == 0 && star[1] != 0)
			ft_hex_znazw(&length, ret_val, 2, numb);
		else if (width == 0 && numb == 0 && star[1] == 0)
			ft_hex_znazw(&length, ret_val, 0, numb);
		else if (width > ft_count_digits(numb))
		{
			*ret_val += (!ft_strchr(flags, '-')) ? ft_wbl1_uns(&length,
			&width, numb) : ft_wbl2_uns(&length, &width, numb, &symb);
		}
		else
			*ret_val += ft_wsl_uns(flags, &length, numb, &symb);
	}
	else
		*ret_val += ft_wz_unsg(flags, &symb, &length, numb);
}

void	ft_uns_init_width(int *width, int *star, char *flags)
{
	int j;

	j = 0;
	if (star[1] == 0)
	{
		while (!ft_strchr(".", flags[j]))
			j++;
		j++;
		while (!ft_strchr("u", flags[j]))
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

int		ft_wbl1_uns(int *length, int *width, int numb)
{
	int i;

	i = 0;
	while ((*length)-- - *width > 0)
	{
		i++;
		write(1, " ", 1);
	}
	while ((*width)-- > ft_count_digits(numb))
	{
		i++;
		write(1, "0", 1);
	}
	i += ft_count_digits(numb);
	ft_putnbr_fd_unsigned(numb, 1);
	return (i);
}

int		ft_wbl2_uns(int *length, int *width, int numb, char *symb)
{
	int buf;
	int i;

	i = 0;
	buf = *width;
	while ((*width)-- > ft_count_digits(numb))
	{
		i++;
		write(1, "0", 1);
	}
	ft_putnbr_fd_unsigned(numb, 1);
	i += ft_count_digits(numb);
	while ((*length)-- - buf > 0)
	{
		i++;
		write(1, &*symb, 1);
	}
	return (i);
}
