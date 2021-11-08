/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetsermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 13:22:54 by festermo          #+#    #+#             */
/*   Updated: 2020/07/02 15:30:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_hex_low(unsigned int numb, char *flags,
		int *star, int *ret_val)
{
	char	symb;
	int		length;
	int		width;

	symb = '\0';
	length = 0;
	width = 0;
	flags = ft_length_init(flags, star, &length, &symb);
	if (ft_strchr(flags, '.'))
	{
		ft_hex_init_width(&width, star, flags);
		if (width == 0 && numb == 0 && star[1] != 0)
			ft_hex_znazw(&length, ret_val, 4, numb);
		else if (width == 0 && numb == 0 && star[1] == 0)
			ft_hex_znazw(&length, ret_val, 0, numb);
		else if (width > (int)ft_strlen(ft_itoa_hex(numb)))
		{
			(!ft_strchr(flags, '-')) ? ft_hex_low_wll1(&width, ret_val, &length,
			numb) : (*ret_val += ft_hex_low_wll2(&width, &length, numb, &symb));
		}
		else
			*ret_val += ft_hex_low_wsl(flags, &length, numb, &symb);
	}
	else
		*ret_val += ft_hex_low_nd(flags, &length, numb, &symb);
}

char	*ft_length_init(char *flags, int *star, int *length, char *symb)
{
	char *joined_str;

	if (ft_strchr(flags, '-') && ft_strchr("0", *flags))
		flags++;
	if (star[0] != 0)
	{
		if (star[0] < 0)
		{
			joined_str = ft_strjoin("-", flags);
			flags = joined_str;
			free(joined_str);
			star[0] = star[0] * -1;
		}
		*length = star[0];
	}
	else
	{
		*length = ft_atoi(flags);
		if (*length < 0)
			*length = *length * -1;
	}
	*symb = (ft_strchr("0", *flags)) ? '0' : ' ';
	return (flags);
}

void	ft_hex_init_width(int *width, int *star, char *flags)
{
	int j;

	j = 0;
	if (star[1] == 0)
	{
		while (!ft_strchr(".", flags[j]))
			j++;
		j++;
		while (!ft_strchr("x", flags[j]))
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

void	ft_hex_low_wll1(int *width, int *ret_val, int *length, int numb)
{
	while ((*length)-- - *width > 0)
	{
		*ret_val += 1;
		write(1, " ", 1);
	}
	while ((*width)-- > (int)ft_strlen(ft_itoa_hex(numb)))
	{
		*ret_val += 1;
		write(1, "0", 1);
	}
	*ret_val += ft_strlen(ft_itoa_hex(numb));
	ft_putstr_fd(ft_itoa_hex(numb), 1);
}

int		ft_hex_low_wll2(int *width, int *length, int numb, char *symb)
{
	int buf;
	int i;

	i = 0;
	buf = *width;
	while ((*width)-- > (int)ft_strlen(ft_itoa_hex(numb)))
	{
		i++;
		write(1, "0", 1);
	}
	i += ft_strlen(ft_itoa_hex(numb));
	ft_putstr_fd(ft_itoa_hex(numb), 1);
	while ((*length)-- - buf > 0)
	{
		i++;
		write(1, &*symb, 1);
	}
	return (i);
}
