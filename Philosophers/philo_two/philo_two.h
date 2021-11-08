#ifndef PHILO_ONE_H
# define PHILO_ONE_H
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct s_philo
{
	int number;
	int to_die;
	int to_eat;
	int to_sleep;
	int times_to_eat;
	//int *forks;
	int now;
	time_t start_time;
	time_t time_now;
	/*pthread_mutex_t left_fork;
	pthread_mutex_t right_fork; */
	//pthread_mutex_t	*forks;      ///////массив вилок
	sem_t *forks;
}			t_philo;

typedef struct s_forks
{
	/*	pthread_mutex_t *left;  ///вилки определенного чубза
	pthread_mutex_t *right;*/
	int id;
	time_t start_time;
		int number;
	int to_die;
	int to_eat;
	int to_sleep;
	int times_to_eat;
	time_t death;
	sem_t *forks;
}						t_forks;

int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char			*ft_itoa(int n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void		ft_putnbr_fd(int nbr, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

time_t		*g_death;
int		*g_times_each_eat;
sem_t	*g_msg;
sem_t	**g_sync;
int		g_dead;

#endif