/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:51:26 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/12 19:15:08 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_eat(t_args *args)
{
	int	actual;

	actual = args->actual;
	// LOCK
	if (args->nb_forks >= 2)
		args->nb_forks -= 2;
	usleep(args->time_to_eat);
	args->nb_forks += 2;

	printf("timestamp_in_ms %d has taken a fork\n", actual);
	//UNLOCK
}

void	*ft_survive(void *data)
{
	t_args *args = (t_args *)data;

	ft_eat(args);




	printf("%d\n", args->time_to_sleep);

	return (NULL);
}

int	ft_launch_philosopers(t_args *args)
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
	}
	i = 0;
	while (i < args->nb_philo)
		pthread_join(args->philosophers[i++], NULL);
	return (0);
}

int	ft_error(int error_code)
{
	if (error_code == 1)
		printf("\e[0;31m[ERROR]\e[0m Wrong amount of arguments\n");
	if (error_code == 2)
		printf("\e[0;31m[ERROR]\e[0m Incorrect arguments\n");
	if (error_code == 3)
		printf("\e[0;31m[ERROR]\e[0m Malloc cannot be created\n");

	return (error_code);
}

int	main(int argc,char **argv)
{
	t_args	args;
	int		error_code;

	if (argc != 5 && argc != 6)
		return (ft_error(1));
	error_code = ft_struct_init(&args, argv);
	if (error_code)
		return (ft_error(error_code));
	//if (ft_launch_philosopers(&args))
	//	return (1);

}
