/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:57:17 by festermo          #+#    #+#             */
/*   Updated: 2020/07/02 18:10:28 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_ptr(long long n, char *flags, int *ret_val, int *star)
{
	char	*b;
	int		length;
	char	*joined_str;

	b = (n == 0 && ft_strchr(flags, '.')) ? "" : ft_itoa_hex_ptr(n);
	if (star[0] < 0)
	{
		if (star[0] < 0)
		{
			joined_str = ft_strjoin("-", flags);
			flags = joined_str;
			free(joined_str);
			star[0] = star[0] * -1;
		}
		length = star[0];
	}
	else
	{
		length = ft_atoi(flags);
		if (length < 0)
			length = length * -1;
	}
	ft_options_ptr(flags, ret_val, &length, b);
}

void	ft_options_ptr(char *flags, int *ret_val, int *length, char *b)
{
	if (ft_strchr(flags, '-'))
	{
		ft_putstr_fd("0x", 1);
		*ret_val += 2;
		ft_putstr_fd(b, 1);
		*ret_val += ft_strlen(b);
		while ((*length)-- > (int)ft_strlen(b) + 2)
		{
			*ret_val += 1;
			write(1, " ", 1);
		}
	}
	else
	{
		while ((*length)-- > (int)ft_strlen(b) + 2)
		{
			*ret_val += 1;
			write(1, " ", 1);
		}
		ft_putstr_fd("0x", 1);
		*ret_val += 2;
		ft_putstr_fd(b, 1);
		*ret_val += ft_strlen(b);
	}
}
