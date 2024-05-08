#include "../include/philo.h"

/*

First step: check valid input
	1. 5 — The number of philosophers
	2. 800 — The time a philosopher will die if he doesn’t eat
	3. 200 — The time it takes a philosopher to eat
	4. 200 — The time it takes a philosopher to sleep
	5. 7 — Number of times all the philosophers need to eat before terminating the program **


Second step: Structure
|------	philo structure:
|		*philos : all of the philosophers
|		*_lock : mutex
|		dead_flag : flag
|------	program structure:
		*_lock : mutex pointers that point to philo mutex
		*_frok : pointers for the fork
		*dead : pointer for the dead_flag
		others : general data

Third step: Initialization	
	keep all the memory on the stack and not on the heap by initializing

Fourth step: Thread creation, Philo routine, and moniter
|	create threads and join
|	1. create threads as many as philosophers
|	2. create extra threads which will moniter(moniter)
|		philo threads run philo routine function
|		observer run monitor function
|	
|------	Philo routine():
|	|	executed so many times
|	|	if dead_flag is 1, break.
|	|
|	|-----	1. think -> print message "X is thinking"
|	|-----	2. sleep -> make them sleep the length of the sleep and print "X is sleeping"
|	|-----	3. eat -> lock the right fork using mutex and do the same thing with left fork
|			  then he will eat and drop the forks by unlock the mutex
|	
|------	Monitor():
	|-----	running infinitely and it has 2 checks
	|	
	|	1.philos dies
	|	2.all ate the number of meals
	|	check the time philo nedds to die didn't surpass the last meal
	|	check he is not concurrently eating
	|	|
	|	|-----	if he indeed dead, change the dead_flag 1, and break the loop in all threads
	|
	|-----	check to see all philos finished eating the amount of meals they need to
		|	
		|-----	yes = change dead_flag 1 and break the loop

Fifth step: destoroy all the mutexes
	destoroy all the mutexes to be able to work program
	free memory if we allocate

*/


static int	check_arguments(int argc, char **argv)
{
	size_t	i;

	i = 1;
	if (argc != 6)
		return (0);
	while (i < 5)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (0)
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_philo		philos[PHILO_MAX];
	t_program	program;
	pthread_mutex_t	mutexes[PHILO_MAX];

	if (argc != 5 && argc != 6)
	{
		write(1, "error", 5);
		return (0);
	}
	if (!check_arguments(argv))
		return (0);
	init_program_structure(&program, philos);
	init_mutexes(mutexes, ft_atoi(argv[1]));
	init_philo_structure(&program, philos, mutexes, argv);
	create_threads(&program, mutexes);
	destroy_threads(&program, mutexes);
	return (0);
}
