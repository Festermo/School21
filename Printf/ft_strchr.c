/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:09:23 by festermo          #+#    #+#             */
/*   Updated: 2020/06/20 16:09:44 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	if (!str)
		return (NULL);
	i = 0;
	if (ch == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
