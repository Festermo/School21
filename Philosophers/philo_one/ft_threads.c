/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:48:24 by festermo          #+#    #+#             */
/*   Updated: 2021/01/27 14:53:13 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_threads(t_philo *philo, t_forks *forks)
{
	int			i;
	pthread_t	t1;
	pthread_t	death;

	i = 0;
	pthread_create(&death, NULL, ft_death, (void *)forks);
	while (i < philo->number)
	{
		forks[i].left = philo->forks + i;
		if (i == philo->number - 1)
			forks[i].right = philo->forks;
		else
			forks[i].right = philo->forks + (i + 1);
		pthread_create(&t1, NULL, ft_life, forks + i);
		pthread_detach(t1);
		usleep(100);
		i++;
	}
	pthread_join(death, NULL);
	pthread_detach(death);
}

void	*ft_life(void *arg)
{
	t_forks	*forks;
	int		i;

	i = 0;
	forks = (t_forks *)arg;
	while (1)
	{
		ft_msg(forks, 2);
		pthread_mutex_lock(forks->left);
		ft_msg(forks, 4);
		pthread_mutex_lock(forks->right);
		ft_msg(forks, 4);
		pthread_mutex_lock(&g_sync[i]);
		ft_msg(forks, 3);
		g_death[forks->id] = ft_get_time() - forks->start_time;
		pthread_mutex_unlock(&g_sync[i]);
		usleep(forks->to_eat * 1000);
		pthread_mutex_unlock(forks->left);
		pthread_mutex_unlock(forks->right);
		if (g_times_each_eat != NULL)
			g_times_each_eat[forks->id]++;
		ft_msg(forks, 1);
		usleep(forks->to_sleep * 1000);
	}
	return (NULL);
}

void	*ft_death(void *arg)
{
	t_forks	*forks;
	int		i;
	int		j;

	forks = (t_forks *)arg;
	j = 0;
	while (1)
	{
		usleep(100);
		i = 0;
		j = 0;
		while (i < forks->number)
		{
			pthread_mutex_lock(&g_sync[i]);
			if (g_death[i] + (time_t)forks->to_die
			< ft_get_time() - forks->start_time)
			{
				ft_msg(forks, 6);
				pthread_mutex_lock(&g_msg);
				return (NULL);
			}
			if ((ft_check_times_to_eat(&i, &j, forks)) == 1)
				return (NULL);
		}
	}
}

int		ft_check_times_to_eat(int *i, int *j, t_forks *forks)
{
	pthread_mutex_unlock(&g_sync[*i]);
	*i += 1;
	if (g_times_each_eat != NULL)
	{
		while (*j < forks->number)
		{
			if (g_times_each_eat[*j] >= forks->times_to_eat)
				*j += 1;
			else
				break ;
			if (*j == forks->number)
			{
				ft_msg(forks, 5);
				pthread_mutex_lock(&g_msg);
				return (1);
			}
		}
	}
	return (0);
}
