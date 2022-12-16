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

int ft_take_forks(t_philo *philo, t_args *args)
{
	if (pthread_mutex_lock(&args->forks[philo->left_fork]))
		return (97);
	ft_print_info(philo, "has taken a fork left");
	if (args->nb_philo > 1)
	{
		if (pthread_mutex_lock(&args->forks[philo->right_fork]))
			return (97);
		ft_print_info(philo, "has taken a fork right");
	}
	return (0);
}

void	ft_release_forks(t_philo *philo, t_args *args)
{
	pthread_mutex_unlock(&args->forks[philo->left_fork]);
	if (args->nb_philo > 1)
		pthread_mutex_unlock(&args->forks[philo->right_fork]);
}

int    ft_eat(t_philo *philo, t_args *args)
{
	//long long	time_diff;
	int			error_code;

	error_code = ft_take_forks(philo, args);
	if (error_code)
		return (error_code);
	//time_diff = ft_time_diff(philo->last_meal, ft_get_time());
	// mutex
	pthread_mutex_lock(&args->block);
	ft_print_info(philo, "is eating");
	philo->last_meal = ft_get_time();

	/*if (time_diff > args->time_to_die)
	{
		args->die = 1;
		ft_print_info(philo, "died");
		pthread_mutex_unlock(&args->block);
		return (1);
	}*/
	// mutex unlock
	usleep(args->time_to_eat);
	philo->nb_meal++;
	if (philo->nb_meal == args->max_meal)
		args->meal_finished++; // MUTEX
	pthread_mutex_unlock(&args->block);
	ft_release_forks(philo, args);
	return (0);
}

static void	*ft_born(void *data)
{
	t_philo	*philo;
	t_args	*args;
	int		error_code;

	philo = (t_philo *)data;
	args = philo->rules;
	while (!args->die)
	{
		error_code = ft_eat(philo, args);
		if (error_code || args->meal_finished == args->nb_philo)
		{
			if (error_code != 1)
				ft_error(error_code);
			break ;
		}
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

	while (args->meal_finished != args->nb_philo && !args->die)
	{
		i = -1;
		while (++i < args->nb_philo)
		{
			pthread_mutex_lock(&args->block);
			time_diff = ft_time_diff(philos[i]->last_meal, ft_get_time());
			if (time_diff > args->time_to_die)
			{
				ft_print_info(philos[i], "died");
				args->die = 1;
			}
			pthread_mutex_unlock(&args->block);
			usleep(1);
		}
		if (args->die)
			break ;
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
