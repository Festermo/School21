/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:44:22 by festermo          #+#    #+#             */
/*   Updated: 2021/01/27 14:47:08 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			ft_init_time_from_last_meal(t_philo *philo, t_forks **forks)
{
	int i;

	i = 0;
	if (!(g_death = (time_t *)malloc(sizeof(time_t) * philo->number)))
	{
		ft_free_globals(philo);
		ft_free_forks(philo);
		free(philo->forks);
		free(*forks);
		exit(0);
	}
	while (i < philo->number)
	{
		g_death[i] = 0;
		i++;
	}
}

void			ft_init_times_to_eat(t_philo *philo)
{
	int i;

	i = 0;
	if (!(g_times_each_eat = (int *)malloc(sizeof(int) * philo->number)))
	{
		ft_free_globals(philo);
		exit(0);
	}
	while (i < philo->number)
	{
		g_times_each_eat[i] = 0;
		i++;
	}
}

void			ft_init_sync(t_philo *philo, t_forks **forks)
{
	int i;

	i = 0;
	if (!(g_sync = malloc(sizeof(pthread_mutex_t) * philo->number)))
	{
		ft_free_globals(philo);
		ft_free_forks(philo);
		free(philo->forks);
		free(*forks);
		exit(0);
	}
	while (i < philo->number)
	{
		g_sync[i] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		i++;
	}
}

pthread_mutex_t	*ft_init_forks(t_philo *philo)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	if (!(forks = malloc(sizeof(pthread_mutex_t) * philo->number)))
	{
		ft_free_globals(philo);
		exit(0);
	}
	while (i < philo->number)
	{
		forks[i] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		i++;
	}
	return (forks);
}
