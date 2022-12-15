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

void	ft_eat(t_philo *philo, t_args *args)
{
	long long	time_diff;

	// LOCK MUTEX
	
	time_diff = ft_time_diff(philo->last_meal, ft_get_time());
	//printf("\t%lli, %lli\n", time_diff, ft_get_time() - args->first_time);
	if (time_diff > args->time_to_die)
	{
		args->die = 1;
		ft_print_info(philo, "is dead");
		return ;
	}
	philo->last_meal = ft_get_time();
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

	while (!args->die)
	{
		//printf("\t\t%d\n", args->die);
		usleep(500);
		ft_eat(philo, args);
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
		usleep(50);
		ret = pthread_create(&philos[i]->thread, NULL, ft_born, philos[i]);
		if (ret)
			return (4);
	}
	ft_wait_threads(args, philos);
	return (0);
}
