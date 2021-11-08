/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:43:41 by festermo          #+#    #+#             */
/*   Updated: 2020/05/08 16:46:06 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const char		*ptr;
	unsigned int	i;
	char			*arr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		arr = (char*)malloc(sizeof(char));
		arr[0] = '\0';
		return (arr);
	}
	ptr = s;
	if (!(arr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len > 0 && ptr[start])
	{
		arr[i++] = ptr[start++];
		len--;
	}
	arr[i] = '\0';
	return (arr);
}
