/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:22:50 by festermo          #+#    #+#             */
/*   Updated: 2020/07/02 15:29:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_par_handling(const char *s,
			int numb_of_par, va_list ap, int *ret_val)
{
	char	*flags;
	char	param;

	if (!(flags = (char *)malloc(ft_strlen(s) + 1)))
		return (++s);
	ft_memset(flags, '\0', ft_strlen(s) + 1);
	param = '\0';
	while (numb_of_par-- > 0)
	{
		s = ft_print_before_param(s, ret_val);
		s = ft_get_flags(s, &flags, &param);
		if (param == '%')
		{
			numb_of_par--;
			ft_which_par(param, flags, ap, ret_val);
		}
		else
			ft_which_par(param, flags, ap, ret_val);
		ft_memset(flags, '\0', ft_strlen(s) + 1);
	}
	free(flags);
	return (s);
}

const char	*ft_get_flags(const char *s, char **flags, char *param)
{
	int i;

	i = 0;
	s++;
	while (ft_strchr("0.*-123456789", *s))
		s = ft_get_flags2(s, flags, &i);
	if (ft_strchr("cspdiuxX%", *s))
	{
		*param = *s;
		(*flags)[i] = '\0';
	}
	else
	{
		*param = '\0';
		(*flags)[0] = '\0';
	}
	return (++s);
}

const char	*ft_print_before_param(const char *s, int *ret_val)
{
	int before_par;
	int i;

	i = 0;
	before_par = 0;
	while (s[i] && s[i] != '%')
	{
		write(1, &s[i], 1);
		i++;
		before_par++;
	}
	*ret_val += before_par;
	return (s + i);
}

int			ft_number_of_params(const char *s)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			res++;
			i++;
		}
		else
			i++;
	}
	return (res);
}

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	int		ret_val;
	int		numb_of_par;

	va_start(ap, s);
	ret_val = 0;
	numb_of_par = ft_number_of_params(s);
	s = ft_par_handling(s, numb_of_par, ap, &ret_val);
	s = ft_print_before_param(s, &ret_val);
	va_end(ap);
	return (ret_val);
}
