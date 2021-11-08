/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:13:02 by festermo          #+#    #+#             */
/*   Updated: 2020/07/02 15:22:26 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printchar(char symb, char *flags, int *ret_val, int *star)
{
	int		length;
	char	delim;

	length = 0;
	delim = '\0';
	flags = ft_length_init(flags, star, &length, &delim);
	if (ft_strchr(flags, '-'))
	{
		write(1, &symb, 1);
		while (length-- > 1)
		{
			write(1, &delim, 1);
			*ret_val += 1;
		}
	}
	else
	{
		while (length-- > 1)
		{
			write(1, &delim, 1);
			*ret_val += 1;
		}
		write(1, &symb, 1);
	}
	*ret_val += 1;
}
