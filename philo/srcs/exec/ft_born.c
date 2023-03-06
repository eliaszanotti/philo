/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_born.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:00:44 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 19:23:49 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_forks(t_philo *philo)
{
	t_args	*args;

	args = philo->rules;
	pthread_mutex_lock(&args->forks[philo->left_fork]);
	if (philo->is_dead)
	{
		pthread_mutex_unlock(&args->forks[philo->left_fork]);
		return (1);
	}
	ft_print_info(philo, "has taken a fork");
	pthread_mutex_lock(&args->forks[philo->right_fork]);
	if (philo->is_dead)
	{
		pthread_mutex_unlock(&args->forks[philo->left_fork]);
		pthread_mutex_unlock(&args->forks[philo->right_fork]);
		return (1);
	}

	if (args->nb_philos != 1)
	ft_print_info(philo, "has taken a fork");

	return (0);
}

int	ft_eat(t_philo *philo)
{
	t_args	*args;

	args = philo->rules;
	if (ft_take_forks(philo))
		return (1);

	


	pthread_mutex_lock(&args->block);
	ft_print_info(philo, "is eating");
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&args->block);
	usleep(args->time_to_eat);
	philo->nb_meal++;
	pthread_mutex_unlock(&args->forks[philo->left_fork]);
	if (args->nb_philos != 1)
		pthread_mutex_unlock(&args->forks[philo->right_fork]);
}

void	*ft_born(t_philo *philo)
{
	t_args	*args;

	args = philo->rules;
	if (args->nb_philos == 1)
	{
		ft_print_info(philo, "is tinking");
		ft_print_info(philo, "has taken a fork");
		return (NULL);
	}
	while (!philo->is_dead)
	{
		ft_print_info(philo, "is thinking");
		if (ft_eat(philo, args))
			return (NULL);
		ft_print_info(philo, "is sleeping");
		usleep(args->time_to_sleep);
	}
	return (NULL);
}
