/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:19:41 by festermo          #+#    #+#             */
/*   Updated: 2021/01/27 15:23:03 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_philo
{
	int				number;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				times_to_eat;
	int				now;
	time_t			start_time;
	time_t			time_now;
	pthread_mutex_t	*forks;
}					t_philo;

typedef struct		s_forks
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int				id;
	time_t			start_time;
	int				number;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				times_to_eat;
	time_t			death;
}					t_forks;

int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
char				*ft_itoa(int n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				ft_putnbr_fd(int nbr, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
pthread_mutex_t		*ft_init_forks(t_philo *philo);
void				ft_threads(t_philo *philo, t_forks *forks);
void				*ft_life(void *arg);
void				*ft_death(void *arg);
int					ft_check_times_to_eat(int *i, int *j, t_forks *forks);
void				ft_init_time_from_last_meal(t_philo *philo,
					t_forks **forks);
void				ft_init_times_to_eat(t_philo *philo);
void				ft_msg(t_forks *forks, int event);
time_t				ft_get_time();
void				ft_check_argv(char **argv, int argc, t_philo *philo);
int					ft_isnumber(char *str);
void				ft_init_sync(t_philo *philo, t_forks **forks);
void				ft_free_globals(t_philo *philo);
void				ft_free_forks(t_philo *philo);
void				ft_init_each_fork(t_philo *philo, t_forks *forks);
void				ft_init_philos_and_forks(t_philo *philo,
					t_forks *forks, char **argv);

time_t				*g_death;
int					*g_times_each_eat;
pthread_mutex_t		*g_sync;
pthread_mutex_t		g_msg;

#endif
