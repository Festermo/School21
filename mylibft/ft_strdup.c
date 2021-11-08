/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:18:33 by festermo          #+#    #+#             */
/*   Updated: 2020/05/07 23:18:40 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*a;
	int		j;

	if (!src)
		return (NULL);
	j = 0;
	i = 0;
	while (src[i])
		i++;
	a = (char*)malloc(i + 1);
	if (a == NULL)
		return (NULL);
	while (src[j])
	{
		a[j] = src[j];
		j++;
	}
	a[j] = '\0';
	return (a);
}
