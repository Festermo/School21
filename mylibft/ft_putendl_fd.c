/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:09:22 by festermo          #+#    #+#             */
/*   Updated: 2020/05/07 23:09:57 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int x;

	if (!s)
		return ;
	x = 0;
	while (s[x])
	{
		if (write(fd, &s[x], 1))
			x++;
		else
			return ;
	}
	if (!(write(fd, "\n", 1)))
		return ;
}
