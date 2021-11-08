/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:56:44 by festermo          #+#    #+#             */
/*   Updated: 2020/05/07 23:03:57 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	char	*ptr;
	char	*ptr1;
	size_t	i;

	ptr = (char *)dest;
	ptr1 = (char *)source;
	i = 0;
	if (!dest && !source)
		return (NULL);
	if (ptr > ptr1)
		while ((int)n > 0 && ptr && ptr1)
		{
			n--;
			ptr[n] = ptr1[n];
		}
	else
	{
		while (i < n && ptr && ptr1)
		{
			ptr[i] = ptr1[i];
			i++;
		}
	}
	return (dest);
}
