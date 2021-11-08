/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 13:27:58 by festermo          #+#    #+#             */
/*   Updated: 2020/07/02 15:22:56 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_hex_low_wsl(char *flags, int *length, int numb, char *symb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex(numb)))
		{
			i++;
			write(1, " ", 1);
		}
		i += ft_strlen(ft_itoa_hex(numb));
		ft_putstr_fd(ft_itoa_hex(numb), 1);
	}
	else
	{
		ft_putstr_fd(ft_itoa_hex(numb), 1);
		i += ft_strlen(ft_itoa_hex(numb));
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex(numb)))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}

int		ft_hex_low_nd(char *flags, int *length, int numb, char *symb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex(numb)))
		{
			i++;
			write(1, &*symb, 1);
		}
		i += ft_strlen(ft_itoa_hex(numb));
		ft_putstr_fd(ft_itoa_hex(numb), 1);
	}
	else
	{
		ft_putstr_fd(ft_itoa_hex(numb), 1);
		i += ft_strlen(ft_itoa_hex(numb));
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex(numb)))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}

void	ft_hex_znazw(int *length, int *ret_val, int which_case, int numb)
{
	if (which_case == 1)
	{
		*ret_val += count_tens(numb, if_negative(numb)) + if_negative(numb);
		ft_putnbr_fd_long(numb, 1);
	}
	if (which_case == 2)
	{
		*ret_val += ft_count_digits(numb);
		ft_putnbr_fd_unsigned(numb, 1);
	}
	if (which_case == 3)
	{
		*ret_val += ft_strlen(ft_itoa_hex_upper(numb));
		ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
	}
	if (which_case == 4)
	{
		*ret_val += ft_strlen(ft_itoa_hex(numb));
		ft_putstr_fd(ft_itoa_hex(numb), 1);
	}
	while ((*length)-- > 0)
	{
		*ret_val += 1;
		write(1, " ", 1);
	}
}
