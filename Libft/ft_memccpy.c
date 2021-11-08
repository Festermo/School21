/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:45:58 by festermo          #+#    #+#             */
/*   Updated: 2020/05/07 22:48:12 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		*ptr1;
	size_t				i;

	if (!dest || !source)
		return (NULL);
	ptr = (unsigned char *)source;
	ptr1 = (unsigned char *)dest;
	i = 0;
	while (i < n && ptr[i])
	{
		if (ptr[i] == (unsigned char)c)
		{
			ptr1[i] = ptr[i];
			return (dest + i + 1);
		}
		ptr1[i] = ptr[i];
		i++;
	}
	return (NULL);
}
