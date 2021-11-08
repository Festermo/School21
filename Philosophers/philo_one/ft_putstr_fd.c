/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:12:50 by festermo          #+#    #+#             */
/*   Updated: 2021/01/18 14:32:56 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_putstr_fd(char *s, int fd)
{
	int x;

	if (!s)
		return ;
	x = 0;
	while (s[x] != '\0')
	{
		if (write(fd, &s[x], 1))
			x++;
		else
			return ;
	}
}
