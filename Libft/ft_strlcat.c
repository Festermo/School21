/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:18:47 by festermo          #+#    #+#             */
/*   Updated: 2020/05/08 16:22:38 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	const char	*ptr1;
	char		*ptr2;

	if (!dst || !src)
		return (0);
	ptr1 = src;
	ptr2 = dst;
	i = 0;
	j = 0;
	while (ptr2[i] && i < size)
		i++;
	while (ptr1[j] && (i + j + 1) < size)
	{
		ptr2[i + j] = ptr1[j];
		j++;
	}
	if (i < size)
		ptr2[i + j] = '\0';
	return (i + ft_strlen(src));
}
