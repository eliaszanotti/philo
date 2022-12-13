#include "philo.h"

int	ft_error(int error_code)
{
	printf("\e[0;31m[ERROR:%d]\e[0m ", error_code);
	if (error_code == 1)
		printf("Wrong amount of arguments\n");
	if (error_code == 2)
		printf("Arguments are not valid integers\n");
	if (error_code == 3)
		printf("Incorrect arguments\n");
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
