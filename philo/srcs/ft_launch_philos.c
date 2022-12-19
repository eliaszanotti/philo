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
	i = -1;
	while (++i < args->nb_philo)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->block);
	pthread_mutex_destroy(&args->printing);
}

void	ft_eat(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&args->forks[philo->left_fork]);
	ft_print_info(philo, "has taken a fork");
	if (args->nb_philo != 1)
		pthread_mutex_lock(&args->forks[philo->right_fork]);
	ft_print_info(philo, "has taken a fork");
	pthread_mutex_lock(&args->block);
	ft_print_info(philo, "is eating");
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&args->block);
	usleep(args->time_to_eat);
	philo->nb_meal++;
	pthread_mutex_unlock(&args->forks[philo->left_fork]);
	if (args->nb_philo != 1)
		pthread_mutex_unlock(&args->forks[philo->right_fork]);
}

static void	*ft_born(void *data)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)data;
	args = philo->rules;
	//if (args->nb_philo % 2)
	//	usleep(10000);
	while (!args->die)
	{
		ft_eat(philo, args);
		if (args->meal_finished)
			return (NULL);
		ft_print_info(philo, "is sleeping");
		usleep(args->time_to_sleep);
		ft_print_info(philo, "is thinking");
	}
	return (NULL);
}

void	ft_wait_death(t_args *args, t_philo **philos)
{
	long long	time_diff;
	int	i;

	while (args->meal_finished == 0)
	{
		i = -1;
		while (++i < args->nb_philo && !args->die)
		{
			pthread_mutex_lock(&args->block);
			time_diff = ft_time_diff(philos[i]->last_meal, ft_get_time());
			if (time_diff > args->time_to_die)
			{
				ft_print_info(philos[i], "died");
				args->die = 1;
			}
			pthread_mutex_unlock(&args->block);
			usleep(100);
		}
		if (args->die)
			break ;
		i = 0;
		while (args->max_meal != -1 && i < args->nb_philo && \
				philos[i]->nb_meal >= args->max_meal) // TODO 11 meal eated when args[5] = 10 
			i++;
		if (i == args->nb_philo)
			args->meal_finished = 1;
	}
}

int	ft_launch_philos(t_args *args, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < args->nb_philo)
		if (pthread_create(&philos[i]->thread, NULL, ft_born, philos[i]))
			return (4);
	ft_wait_death(args, philos);
	ft_wait_threads(args, philos);
	return (0);
}
