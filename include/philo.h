#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define PHILO_MAX 300

typedef struct s_philo
{
	pthread_t	thread;
	int		id;
	int		eating;
	int		meals_eaten;
	size_t		last_meal;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		start_time;
	int		num_of_philos;
	int		num_times_to_eat;
	int		*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}t_philo;

typedef struct s_program
{
	int		dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo		*philos;
}t_program;
