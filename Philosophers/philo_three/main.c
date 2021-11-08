#include "philo_one.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <signal.h>

time_t ft_get_time()
{
	struct timeval cur_time;
	gettimeofday(&cur_time, NULL);

	return ((cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000));
}

void *ft_time(void *arg)
{
	t_forks *forks;

	forks = (t_forks *)arg;
	while (g_dead == 0)
	{
		//usleep(1000);
		//ft_putnbr_fd(forks->start_time, 1);
		//write(1, "\n", 1);
		sem_wait(g_sync[forks->id]);
		g_death[forks->id] = ft_get_time() - forks->start_time;
		if (g_times_each_eat != NULL)
			g_times_each_eat[forks->id]++;
		//ft_putnbr_fd(forks->id, 1);
		//write(1, "\n", 1);
		//sem_post(g_sync[forks->id]);
	}
	return (NULL);
}

void ft_init_pids(t_philo *philo)
{
	int i;

	i = 0;
	g_pids = (pid_t *)malloc(sizeof(pid_t) * philo->number);
	while (i < philo->number)
	{
		g_pids[i] = 0;
		i++;
	}
}

void ft_free_globals()
{
	if (g_times_each_eat != NULL)
	{
		free(g_times_each_eat);
		g_times_each_eat = NULL;
	}
	if (g_times_each_eat != NULL)
	{
		free(g_death);
		g_death = NULL;
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

void ft_kill_proc(int number)
{
	int i;

	i = 0;
	while (i < number)
	{
		//if (g_pids[i] != 0)
		kill(g_pids[i], SIGKILL);
		i++;
	}
}

sem_t *ft_init_forks(t_philo *philo)
{
	sem_t *forks;

	sem_unlink("forks");
	forks = sem_open("forks", O_CREAT, 0, philo->number);
	return(forks);
}

void	ft_init_times_to_eat(t_philo *philo)
{
	int i;

	i = 0;
	if (!(g_times_each_eat = (int *)malloc(sizeof(int) * philo->number)))
		exit (0);
	while (i < philo->number)
	{
		g_times_each_eat[i] = 0;
		i++;
	}
}

void ft_check_argv(char **argv, int argc)
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
			exit (0);
		}
	}
}

void	ft_init_time_from_last_meal(t_philo *philo, t_forks **forks)
{
	int i;

	i = 0;
	//if (!(g_death = (int *)malloc(sizeof(int) * philo->number)))
	if (!(g_death = (time_t *)malloc(sizeof(time_t) * philo->number)))
	{
		ft_free_globals();
		free(philo->forks);
		free(*forks);
		exit(0);
	}
	while (i < philo->number)
	{
		//g_death[i] = ft_get_time() - philo->start_time;
		//g_death[i] = 5;
		g_death[i] = 0;
		i++;
	}
}

void ft_msg(t_forks *forks, int event)
{
	//static pthread_mutex_t msg = PTHREAD_MUTEX_INITIALIZER;

	//pthread_mutex_lock(&g_msg);
	sem_wait(g_msg);
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
		//exit (0);
	}
	if (event == 6)
	{
		write(1, "\tdied\n", 6);
		//ft_free_globals();
		//exit (0);
	}
	if (g_dead != 1)
		sem_post(g_msg);
	//pthread_mutex_unlock(&g_msg);
}

void ft_init_sync(t_philo *philo)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 6);
	g_sync = (sem_t **)malloc(sizeof(sem_t *) * philo->number);
	str[5] = '\0';
	str[0] = 's';
	str[1] = 'y';
	str[2] = 'n';
	str[3] = 'c';
	while (i < philo->number)
	{
		str[4] = i + 1;
		sem_unlink(str);
		g_sync[i] = sem_open(str, O_CREAT, 0, 1);
		//g_sync[i] = sem_open(str, O_CREAT);
		//sem_post(g_sync[i]);
		i++;
	}
}

void *ft_death(void *arg)
{
	t_forks *forks;
	int i;
	int j;

	forks = (t_forks *)arg;
	i = 0;
	j = 0;
	while (1)
	{
		usleep(50);
		i = 0;
		j = 0;
		while(i < forks->number)
		{
			//pthread_mutex_lock(&g_sync);
			//sem_wait(g_sync[forks->id]);
			//ft_putnbr_fd(forks->to_die, 1);
			//write(1, "\n", 1);
			if (g_death[i]  + (time_t)forks->to_die < ft_get_time() - forks->start_time)
			{
				g_dead = 1;
				ft_msg(forks, 6);
				//return (0);
				//write(1, "BBB", 3);
				//ft_kill_proc(forks->number);
				//sem_wait(g_msg);
				//pthread_mutex_lock(&g_msg);
				return (NULL);
				//return (NULL);
				//exit (0);
			}
			sem_post(g_sync[forks->id]);
			//pthread_mutex_unlock(&g_sync);
			i++;
			if (g_times_each_eat != NULL)
			{
				while (j < forks->number)
				{
					if (g_times_each_eat[j] >= forks->times_to_eat)
					{
						j++;
						//continue;
					}
					else
						break;
					if (j == forks->number )
					{
						g_dead = 1;
						ft_msg(forks, 5);
						//pthread_mutex_lock(&g_msg);
						
						//sem_wait(g_msg);
						//sem_wait(g_msg);
						//
						return (NULL);
						//exit(0);
					}
				}
			}
		}
	}
}

void *ft_life(void *arg)
{
	t_forks *forks;
	int i;

	i = 0;
	forks = (t_forks *)arg;
	//write(1, "A", 1);
	while (1)
	{
		/*ft_putnbr_fd(forks->id, 1);
		write(1, "lol\n", 4);*/
		ft_msg(forks,2);
		//usleep(1000);
		sem_wait(forks->forks);
		//pthread_mutex_lock(forks->left);
		ft_msg(forks, 4);
		//pthread_mutex_lock(forks->right);
		sem_wait(forks->forks);
		ft_msg(forks, 4);
		//pthread_mutex_lock(&g_sync);
		//sem_wait(g_sync[forks->id]);
		sem_post(g_sync[forks->id]);
		ft_msg(forks, 3);
		//pthread_mutex_lock(&g_sync);
		//g_death[forks->id] = ft_get_time() - forks->start_time + forks->to_eat;
		//g_death[forks->id] = ft_get_time() - forks->start_time;
		//sem_post(g_sync[forks->id]);
		//pthread_mutex_unlock(&g_sync);
		usleep(forks->to_eat * 1000);
		sem_post(forks->forks);
		sem_post(forks->forks);
		//pthread_mutex_unlock(forks->left);
		//pthread_mutex_unlock(forks->right);
		//if (g_times_each_eat != NULL)
		//	g_times_each_eat[forks->id]++;
		ft_msg(forks, 1);
		usleep(forks->to_sleep * 1000);
	}
	return (NULL);
}

void ft_threads(t_philo *philo, t_forks *forks)
{
	int i;
	//pid_t pid;
	pthread_t death;
	pthread_t t1;

	i = 0;
	pthread_create(&death, NULL, ft_death, (void *)forks);
	while (i < philo->number)
	{
		forks[i].forks = philo->forks;
		//pid = fork();
		//if (!(g_pids[i] = fork()))
		//ft_putnbr_fd(g_pids[i], 1);
		///write(1, "\n", 1);
		g_pids[i] = fork();
		if (g_pids[i] == 0)
		{
			ft_life(forks + i);
			//break;
		}
		pthread_create(&t1, NULL, ft_time, forks + i);
		pthread_detach(t1);
		////////PRIDUMAY CHTO S ETIM DELAT NE RABOTAET
		//waitpid(pid, 0, 0);
		//exit(0);
		usleep(100);
		i++;
	}
	pthread_join(death, NULL);
	//usleep(1000000);
	//write(1, "AAA", 3);
	ft_kill_proc(philo->number);
}

int main(int argc, char **argv)
{
	t_philo philo;
	t_forks *forks;
	int i;

	g_dead = 0;
	sem_unlink("msg");
	g_msg = sem_open("msg", O_CREAT, 0, 0);
	sem_post(g_msg);
	i = 0;
	ft_check_argv(argv, argc);
	g_times_each_eat = NULL;
	g_death = NULL;
	philo.number = ft_atoi(argv[1]);
	if (argc == 6)
	{
		philo.times_to_eat = ft_atoi(argv[5]);
		ft_putnbr_fd(philo.times_to_eat, 1);
		ft_init_times_to_eat(&philo);
	}
	////osuda free globals
	if (argc != 5 && argc != 6)
	{
		write(1, "wrong arguments\n", 16);
		return (0);
	}
	
	philo.start_time = ft_get_time();
	//philo.number = ft_atoi(argv[1]);
	philo.to_die = ft_atoi(argv[2]);
	philo.to_eat = ft_atoi(argv[3]);
	philo.to_sleep = ft_atoi(argv[4]);
	philo.forks = ft_init_forks(&philo);
	////otsuda philo.forks free
	if (!(forks = (t_forks *)malloc(sizeof(t_forks) * (philo.number))))
	{
		ft_free_globals();
		//free(philo.forks);
		///podumay
		exit(0);
	}
	///otsuda eche forks free
	forks->start_time = ft_get_time();
	forks->number = ft_atoi(argv[1]);
	forks->to_die = ft_atoi(argv[2]);
	forks->to_eat = ft_atoi(argv[3]);
	forks->to_sleep = ft_atoi(argv[4]);
	forks->times_to_eat = ft_atoi(argv[5]);
	ft_init_time_from_last_meal(&philo, &forks);
	ft_init_sync(&philo);
	ft_init_pids(&philo);
	//sem_unlink("sync");
	while (i < philo.number)
	{
		forks[i].id = i;
		forks[i].to_sleep = philo.to_sleep;
		forks[i].to_eat = philo.to_eat;
		forks[i].start_time = philo.start_time;
		forks[i].death = 0;
		forks[i].times_to_eat = philo.times_to_eat;
		forks[i].to_die = philo.to_die;
		forks[i].number = philo.number;
		//forks[i].sync = sem_open("sync", O_CREAT, 0, 1);
		i++;
	}
	ft_threads(&philo, forks);
	//free(philo.forks);
	free(forks);
	ft_free_globals();
	return (0);
}
