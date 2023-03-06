/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event01 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:46:53 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 12:21:08 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

