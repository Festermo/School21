/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 13:05:30 by festermo          #+#    #+#             */
/*   Updated: 2020/06/20 13:20:12 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_hex(unsigned int value)
{
	static char	rep[] = "0123456789abcdef";
	static char	buf[50];
	char		*ptr;

	ptr = &buf[49];
	*ptr = '\0';
	if (value == 0)
		*--ptr = rep[value % 16];
	while (value != 0)
	{
		*--ptr = rep[value % 16];
		value /= 16;
	}
	return (ptr);
}

char	*ft_itoa_hex_upper(unsigned int value)
{
	static char	rep[] = "0123456789ABCDEF";
	static char	buf[50];
	char		*ptr;

	ptr = &buf[49];
	*ptr = '\0';
	if (value == 0)
		*--ptr = rep[value % 16];
	while (value != 0)
	{
		*--ptr = rep[value % 16];
		value /= 16;
	}
	return (ptr);
}

char	*ft_itoa_hex_ptr(unsigned long value)
{
	static char				rep[] = "0123456789abcdef";
	static char				buf[50];
	char					*ptr;

	ptr = &buf[49];
	*ptr = '\0';
	if (value == 0)
		*--ptr = rep[value % 16];
	while (value != 0)
	{
		*--ptr = rep[value % 16];
		value /= 16;
	}
	return (ptr);
}
