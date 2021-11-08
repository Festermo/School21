/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 13:33:58 by festermo          #+#    #+#             */
/*   Updated: 2020/06/20 13:40:59 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_hex_up(unsigned int numb, char *flags, int *star, int *ret_val)
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
			ft_hex_znazw(&length, ret_val, 3, numb);
		else if (width == 0 && numb == 0 && star[1] == 0)
			ft_hex_znazw(&length, ret_val, 0, numb);
		else if (width > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			(!ft_strchr(flags, '-')) ? ft_hex_up_wll1(&width, ret_val, &length,
			numb) : (*ret_val += ft_hex_up_wll2(&width, &length, numb, &symb));
		}
		else
			*ret_val += ft_hex_up_wsl(flags, &length, numb, &symb);
	}
	else
		*ret_val += ft_hex_up_nd(flags, &length, numb, &symb);
}

void	ft_hex_up_wll1(int *width, int *ret_val, int *length, int numb)
{
	while ((*length)-- - *width > 0)
	{
		*ret_val += 1;
		write(1, " ", 1);
	}
	while ((*width)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
	{
		*ret_val += 1;
		write(1, "0", 1);
	}
	*ret_val += ft_strlen(ft_itoa_hex_upper(numb));
	ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
}

int		ft_hex_up_wll2(int *width, int *length, int numb, char *symb)
{
	int buf;
	int i;

	i = 0;
	buf = *width;
	while ((*width)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
	{
		i++;
		write(1, "0", 1);
	}
	i += ft_strlen(ft_itoa_hex_upper(numb));
	ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
	while ((*length)-- - buf > 0)
	{
		i++;
		write(1, &*symb, 1);
	}
	return (i);
}

int		ft_hex_up_wsl(char *flags, int *length, int numb, char *symb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			i++;
			write(1, " ", 1);
		}
		i += ft_strlen(ft_itoa_hex_upper(numb));
		ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
	}
	else
	{
		ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
		i += ft_strlen(ft_itoa_hex_upper(numb));
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}

int		ft_hex_up_nd(char *flags, int *length, int numb, char *symb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			i++;
			write(1, &*symb, 1);
		}
		i += ft_strlen(ft_itoa_hex_upper(numb));
		ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
	}
	else
	{
		ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
		i += ft_strlen(ft_itoa_hex_upper(numb));
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}
