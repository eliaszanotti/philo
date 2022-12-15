/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event01 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:46:53 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/14 15:35:53 by event01          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_wait_threads(t_args *args, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < args->nb_philo)
		pthread_join(philos[i]->thread, NULL);
}

int	ft_eat(t_philo *philo, t_args *args)
{
	long long	time_diff;

	// LOCK MUTEX
	time_diff = ft_time_diff(philo->last_meal, ft_get_time());
	printf("%lli\tdie = %d\n", time_diff, args->time_to_die);
	if (time_diff > args->time_to_die)
	{
		args->die = 1;
		ft_print_info(philo, "died");
		return (1);
	}
	philo->last_meal = ft_get_time();
	philo->nb_meal++;
	if (philo->nb_meal == args->max_meal)
		args->meal_finished++; // MUTEX
	//printf("FINS : %d\n", args->meal_finished);
	ft_print_info(philo, "is eating");
	usleep(args->time_to_eat);
	// UNLOCK MUTEX	
	return (0);
}

static void	*ft_born(void *data)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)data;
	args = philo->rules;
	while (1)
	{
		if (ft_eat(philo, args) || args->meal_finished == args->nb_philo)
			return (NULL);
		ft_print_info(philo, "is sleeping");
		usleep(args->time_to_sleep);
		ft_print_info(philo, "is thinking");
	}
	return (NULL);
}

int	ft_launch_philos(t_args *args, t_philo **philos)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < args->nb_philo)
	{
		usleep(500);
		ret = pthread_create(&philos[i]->thread, NULL, ft_born, philos[i]);
		if (ret)
			return (4);
	}
	ft_wait_threads(args, philos);
	return (0);
}
