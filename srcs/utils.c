#include "../include/philo.h"

int	ft_handle_sign(const char *str, int *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			sign *= -1;
		(*index)++;
	}
	return (sign);
}

int	ft_handle_overflow(const char *str, int index, int sign, long long result)
{
	if (result > LONG_MAX / 10 && sign != -1)
		return (-1);
	else if (result > LONG_MAX / 10 && sign == -1)
		return (0);
	else if (result == LONG_MAX / 10)
	{
		index++;
		if (str[index] > '6' && sign != -1)
			return (-1);
		else if (str[index] > '7' && sign == -1)
			return (0);
		return (1);
	}
	return (2);
}

int	ft_atoi(const char *str)
{
	int			index;
	long long	result;
	int			sign;
	int			overflow;

	index = 0;
	result = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	sign = ft_handle_sign(str, &index);
	if (ft_strncmp(str, "9223372036854775806", 19) == 0)
		return (-2);
	while (ft_isdigit(str[index]))
	{
		result = (result * 10) + (str[index] - '0');
		overflow = ft_handle_overflow(str, index, sign, result);
		if (overflow != 2)
			return (overflow);
		index++;
	}
	return (result * sign);
}

size_t	get_current_time()
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time->tv_sec * 1000 + time->tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < milliseconds)
		usleep(500);
	return (0);
}
