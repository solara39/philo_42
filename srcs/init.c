#include "../include/philo.h"

void	init_program_structure(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	pthread_mutex_lock(&program->dead_lock, NULL);
	pthread_mutex_lock(&program->meal_lock, NULL);
	pthread_mutex_lock(&program->write_lock, NULL);
	program->philos = philos;
}

void	init_philo_structure(t_program *program, t_philo *philos, pthread_mutex_t *forks, char **argv)
{
	int i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i]->id = i;
		philos[i]->eating = 0;
		philos[i]->meals_eaten = 0;
		philos[i]->last_meal = get_current_time();
		philos[i]->time_to_die = ft_atoi(argv[2]);
		philos[i]->time_to_eat = ft_atoi(argv[3]);
		philos[i]->time_to_sleep =ft_atoi(argv[4]);
		philos[i]->start_time = ge_current_time();
		philos[i]->num_of_philos = ft_atoi(argv[1]);
		if (argv[5])
			philos[i]->num_times_to_eat = ft_atoi(argv[5]);
		else
			philos[i]->num_times_to_eat = -1; 
		philos[i]->dead = &program->dead_flag;
		if (i == 0)
			philos[i]->r_fork = &mutexes[philos[i]->num_of_philos - 1]
		else
			philos[i]->r_fork = &mutexes[i - 1];
		philos[i]->l_fork = &mutexes[i];
		philos[i]->write_lock = &program->write_lock;
		philos[i]->dead_lock = &prigram->dead_lock;
		philos[i]->meal_lock = &program->meal_lock;
		i++;
	}
}

void	init_mutexes(t_philo *forks, int philo_num)
{
	size_t	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_lock(forks[i], NULL);
		i++;
	}
}
