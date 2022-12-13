// HEADER

#include "philo.h"

static void	*ft_born(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		printf("test venant de %d\n", philo->nb);
		sleep(1);

	}

	return (NULL);
}

static void	ft_wait_threads(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nb_philo)
		pthread_join(args->philos[i].thread, NULL);
}

int	ft_launch_philos(t_args *args)
{
	t_philo	*philos;
	int	i;
	int	ret;

	philos = args->philos;
	i = -1;
	while (++i < args->nb_philo)
	{
		usleep(500);
		ret = pthread_create(&(philos[i].thread), NULL, ft_born, &philos[i]);
		usleep(500);
		if (ret)
			return (4);
	}
	return (0);
}


/*void *test(void *ar)
{
	while (1)
	{
		printf("f \n");
		sleep(30);
	}
	(void)ar;
	return (NULL);
}*/

/*void	ft_eat(t_args *args)
{
	// LOCK
	if (args->nb_forks >= 2)
		args->nb_forks -= 2;
	usleep(args->time_to_eat);
	args->nb_forks += 2;

	//UNLOCK
}

void	*ft_survive(void *data)
{
	t_args *args = (t_args *)data;

	ft_eat(args);




	printf("%d\n", args->time_to_sleep);

	return (NULL);
}*/

/*int	ft_launch_philosopers(t_args *args)
{
	int	i;
	int	ret;

	i = 0;
	while (i < args->nb_philo)
	{
		args->actual = i;
		ret = pthread_create(&args->philosophers[i++], NULL, ft_survive, \
			(void *)args);
		if (ret)
			return (1);
		usleep(50000);
