/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:31:08 by festermo          #+#    #+#             */
/*   Updated: 2021/01/15 12:44:13 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	ft_atoi(const char *str)
{
	int		j;
	long	numb;
	int		sgn;

	if (!str)
		return (0);
	j = 0;
	numb = 0;
	sgn = 1;
	while (str[j] == '\v' || str[j] == '\t' || str[j] == '\n'
	|| str[j] == '\f' || str[j] == '\r' || str[j] == ' ')
		j++;
	if (str[j] == '-' || str[j] == '+')
		if (str[j++] == '-')
			sgn = -1;
	while (str[j] >= '0' && str[j] <= '9')
	{
		if (numb > (numb * 10 + (str[j] - '0')))
			return (sgn > 0 ? -1 : 0);
		numb = (numb * 10) + (str[j++] - '0');
	}
	return ((int)(numb * sgn));
}
