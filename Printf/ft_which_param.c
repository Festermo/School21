/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:13:33 by festermo          #+#    #+#             */
/*   Updated: 2020/06/24 13:57:44 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_which_par(char param, char *flags, va_list ap, int *ret_val)
{
	int *star;

	star = (int *)malloc(sizeof(int) * 2);
	star = get_star(flags, ap, star);
	if (param == 'c')
		ft_printchar(va_arg(ap, int), flags, ret_val, star);
	if (param == '%')
		ft_printchar('%', flags, ret_val, star);
	if (param == 'd' || param == 'i')
		ft_printnbr(va_arg(ap, int), flags, star, ret_val);
	if (param == 's')
		ft_print_str(va_arg(ap, char *), flags, star, ret_val);
	if (param == 'u')
		ft_print_unsigned(va_arg(ap, int), flags, star, ret_val);
	if (param == 'x')
		ft_print_hex_low(va_arg(ap, unsigned int), flags, star, ret_val);
	if (param == 'X')
		ft_print_hex_up(va_arg(ap, unsigned int), flags, star, ret_val);
	if (param == 'p')
		ft_print_ptr(va_arg(ap, long long), flags, ret_val, star);
	free(star);
}

int			*get_star(char *flags, va_list ap, int *star)
{
	int i;
	int j;

	i = 0;
	j = 0;
	star[0] = 0;
	star[1] = 0;
	while (flags[i] && ft_strchr(flags, '*'))
	{
		if (flags[i] == '*')
			j++;
		i++;
	}
	if (j == 2)
	{
		star[0] = va_arg(ap, int);
		star[1] = va_arg(ap, int);
	}
	else if (j > 0 && ft_strrchr(flags, '*') >
	ft_strrchr(flags, '.') && ft_strrchr(flags, '.'))
		star[1] = va_arg(ap, int);
	else if (j > 0)
		star[0] = va_arg(ap, int);
	return (star);
}

const char	*ft_get_flags2(const char *s, char **flags, int *i)
{
	if (*s == '-')
	{
		if (!ft_strchr(*flags, '-'))
		{
			(*flags)[*i] = *s;
			*i += 1;
		}
		s++;
	}
	else if (*s == '0')
	{
		if (ft_strchr(*flags, '-') || !(*(s - 1) == '0'))
		{
			(*flags)[*i] = *s;
			*i += 1;
		}
		s++;
	}
	else
	{
		(*flags)[*i] = *s;
		s++;
		*i += 1;
	}
	return (s);
}
