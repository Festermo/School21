/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:11:33 by festermo          #+#    #+#             */
/*   Updated: 2020/06/20 16:11:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*arr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	arr = (char*)malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		arr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		arr[i] = s2[j];
		j++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
