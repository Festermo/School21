/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:42:53 by festermo          #+#    #+#             */
/*   Updated: 2021/01/27 14:43:08 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_free_forks(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->number)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
}

void	ft_free_globals(t_philo *philo)
{
	int i;

	i = 0;
	if (g_times_each_eat != NULL)
	{
		free(g_times_each_eat);
		g_times_each_eat = NULL;
	}
	if (g_death != NULL)
	{
		free(g_death);
		g_death = NULL;
	}
	pthread_mutex_destroy(&g_msg);
	if (g_sync != NULL)
	{
		while (i < philo->number)
		{
			pthread_mutex_destroy(&g_sync[i]);
			i++;
		}
	}
}
