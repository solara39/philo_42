#include "../include/philo.h"

int	create_threads(t_program *program, pthread_mutex_t *mutexes)
{
	pthread_t	observer;
	int		i;

	pthread_create(&observer, NULL, func, program->philos);
	i = 0;
	while (i < program->philos[0]->num_of_philos)
	{
		pthread_create(&program->philos[i]->thread, NULL, func, program->philos);
		i++;
	}
	pthread_join(&observer, NULL);
	i = 0;
	while (i < program->philos[0]->num_of_philos)
	{
		pthread_joim(&program->philos[i]->thread, NULL);
		i++;
	}
	return (0);
}
