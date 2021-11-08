/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:14:41 by festermo          #+#    #+#             */
/*   Updated: 2021/01/27 15:15:13 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_init_philos_and_forks(t_philo *philo, t_forks *forks, char **argv)
{
	philo->start_time = ft_get_time();
	philo->to_die = ft_atoi(argv[2]);
	philo->to_eat = ft_atoi(argv[3]);
	philo->to_sleep = ft_atoi(argv[4]);
	philo->forks = ft_init_forks(philo);
	forks->start_time = philo->start_time;
	forks->number = ft_atoi(argv[1]);
	forks->to_die = ft_atoi(argv[2]);
	forks->to_eat = ft_atoi(argv[3]);
	forks->to_sleep = ft_atoi(argv[4]);
	forks->times_to_eat = ft_atoi(argv[5]);
}

void	ft_init_each_fork(t_philo *philo, t_forks *forks)
{
	int i;

	i = 0;
	while (i < philo->number)
	{
		forks[i].id = i;
		forks[i].to_sleep = philo->to_sleep;
		forks[i].to_eat = philo->to_eat;
		forks[i].start_time = philo->start_time;
		forks[i].death = 0;
		forks[i].times_to_eat = philo->times_to_eat;
		forks[i].to_die = philo->to_die;
		forks[i].number = philo->number;
		i++;
	}
}

void	ft_check_argc(t_philo *philo, char **argv, int argc)
{
	if (argc == 6)
	{
		philo->times_to_eat = ft_atoi(argv[5]);
		ft_init_times_to_eat(philo);
	}
	if (argc != 5 && argc != 6)
	{
		write(1, "wrong arguments\n", 16);
		ft_free_globals(philo);
		exit(0);
	}
}

void	ft_init_globals(void)
{
	g_sync = NULL;
	g_death = NULL;
	g_times_each_eat = NULL;
	g_msg = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
}

int		main(int argc, char **argv)
{
	t_philo philo;
	t_forks *forks;

	ft_init_globals();
	ft_check_argv(argv, argc, &philo);
	philo.number = ft_atoi(argv[1]);
	ft_check_argc(&philo, argv, argc);
	if (!(forks = (t_forks *)malloc(sizeof(t_forks) * (philo.number))))
	{
		ft_free_globals(&philo);
		ft_free_forks(&philo);
		free(philo.forks);
		exit(0);
	}
	ft_init_philos_and_forks(&philo, forks, argv);
	ft_init_time_from_last_meal(&philo, &forks);
	ft_init_sync(&philo, &forks);
	ft_init_each_fork(&philo, forks);
	ft_threads(&philo, forks);
	ft_free_forks(&philo);
	free(philo.forks);
	free(forks);
	ft_free_globals(&philo);
	return (0);
}
