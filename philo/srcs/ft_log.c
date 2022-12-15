#include "philo.h"

int	ft_error(int error_code)
{
	printf("\e[0;31m[ERROR:%d]\e[0m ", error_code);
	if (error_code == 1)
		printf("Wrong amount of arguments\n");
	if (error_code == 2)
		printf("Arguments are not valid integers\n");
	if (error_code == 3)
		printf("Incorrect arguments (max number of philosophers is 256)\n");
	if (error_code == 4)
		printf("Impossible to create threads\n");
	if (error_code == 9)
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
	long long	first_time;
	long long	time_diff;
	t_args		*args;

	args = philo->rules;
	first_time = args->first_time;
	time_diff = ft_time_diff(first_time, ft_get_time());
	printf("\033[1;32m[%lli ms]\033[0m \033[0;32m%d\033[0m %s\n", \
		time_diff, philo->nb, str);
}
