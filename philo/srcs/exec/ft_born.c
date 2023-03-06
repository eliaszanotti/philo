/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_born.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:00:44 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 20:51:51 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_take_forks(t_philo *philo)
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
	ft_print_info(philo, "has taken a fork");
	return (0);
}

static int	ft_eat(t_philo *philo)
{
	t_args	*args;

	args = philo->rules;
	if (ft_take_forks(philo))
		return (1);
	ft_print_info(philo, "is eating");
	pthread_mutex_lock(&args->block);
	philo->last_meal = ft_get_time();
	philo->nb_meal++;
	pthread_mutex_unlock(&args->block);
	usleep(args->time_to_eat);
	pthread_mutex_unlock(&args->forks[philo->left_fork]);
	pthread_mutex_unlock(&args->forks[philo->right_fork]);
	if (philo->is_dead)
		return (1);
	return (0);
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
		if (ft_eat(philo))
			return (NULL);
		ft_print_info(philo, "is sleeping");
		usleep(args->time_to_sleep);
	}
	return (NULL);
}
