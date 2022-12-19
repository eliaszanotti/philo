#include "philo.h"

int	ft_error(int error_code)
{
	if (error_code)
		printf("\e[1;31m[ERROR:%d]\e[0m ", error_code);
	if (error_code == 1)
		printf("Wrong amount of arguments\n");
	if (error_code == 2)
		printf("Arguments are not valid integers\n");
	if (error_code == 3)
		printf("Incorrect arguments (max number of philosophers is 256)\n");
	if (error_code == 4)
		printf("Impossible to create threads\n");
	if (error_code == 97)
		printf("Impossible to lock mutex\n");
	if (error_code == 98)
		printf("Mutex cannot be initialized\n");
	if (error_code == 99)
		printf("Malloc cannot be created\n");
	return (error_code);
}

int	ft_argv_checker(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (2);
	}
	return (0);
}

void	ft_print_info(t_philo *philo, char *str)
{
	long long	time_diff;
	t_args		*args;

	args = philo->rules;
	time_diff = ft_time_diff(args->first_time, ft_get_time());
	if (!args->die)
	{
		printf("\033[1;32m[%lli ms]\033[0m \033[0;32m%d\033[0m %s\n", \
			time_diff, philo->nb + 1, str);
	}
}
