/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:53:55 by festermo          #+#    #+#             */
/*   Updated: 2021/01/27 14:55:18 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

time_t	ft_get_time(void)
{
	struct timeval cur_time;

	gettimeofday(&cur_time, NULL);
	return ((cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000));
}

void	ft_check_argv(char **argv, int argc, t_philo *philo)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]))
			i++;
		else
		{
			write(1, "wrong arguments\n", 16);
			ft_free_globals(philo);
			exit(0);
		}
	}
}

int		ft_isnumber(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' ||
		str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7'
		|| str[i] == '8' || str[i] == '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_msg(t_forks *forks, int event)
{
	pthread_mutex_lock(&g_msg);
	ft_putnbr_fd(ft_get_time() - forks->start_time, 1);
	write(1, "\t", 1);
	if (event != 5)
		ft_putnbr_fd(forks->id + 1, 1);
	if (event == 1)
		write(1, "\tis sleeping\n", 13);
	if (event == 2)
		write(1, "\tis thinking\n", 13);
	if (event == 3)
		write(1, "\tis eating\n", 11);
	if (event == 4)
		write(1, "\thas taken a fork\n", 18);
	if (event == 5)
	{
		write(1, "\tphilosophers ate enough\n", 25);
	}
	if (event == 6)
	{
		write(1, "\tdied\n", 6);
	}
	pthread_mutex_unlock(&g_msg);
}
