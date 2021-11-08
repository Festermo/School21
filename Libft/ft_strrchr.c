/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:40:18 by festermo          #+#    #+#             */
/*   Updated: 2020/05/08 16:41:49 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (ch == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == ch)
			j = i;
		i++;
	}
	if (j == 0)
	{
		if (str[0] == ch)
			return ((char *)str);
		else
			return (NULL);
	}
	return ((char *)str + j);
}
