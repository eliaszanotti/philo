/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event01 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:46:53 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/14 14:31:22 by event01          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_info(t_philo *philo, char *str)
{
	long long	first_time;
	long long	time_diff;
	t_args		*args;

	args = philo->rules;
	first_time = args->first_time;
	time_diff = ft_time_diff(first_time, ft_get_time());
	printf("[\033[4;32m%lli\033[0m] \033[0;32m%d\033[0m %s\n", \
		time_diff, philo->nb, str);
}

static void	ft_wait_threads(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nb_philo)
		pthread_join(args->philos[i].thread, NULL);
}

void	ft_eat(t_philo *philo, t_args *args)
{
	// LOCK MUTEX
	
	


	ft_print_info(philo, "is eating");
	usleep(args->time_to_eat);






	(void)philo;

	// UNLOCK MUTEX	

}

static void	*ft_born(void *data)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)data;
	args = philo->rules;
	while (1) // change to while not died 
	{
		usleep(500);
		ft_eat(philo, args);
		ft_print_info(philo, "is sleeping");
		usleep(args->time_to_sleep);
		ft_print_info(philo, "is thinking");
	}
	return (NULL);
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
		usleep(50);
		ret = pthread_create(&philos[i].thread, NULL, ft_born, &philos[i]);
		if (ret)
			return (4);
	}
	ft_wait_threads(args);
	return (0);
}
