/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:23:30 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 12:06:34 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_struct_init(t_args *args, char **argv)
{
	args->nb_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]) * 1000;
	args->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (args->nb_philo < 1 || args->nb_philo > 256 || args->time_to_die < 0 \
			|| args->time_to_eat < 0 || args->time_to_sleep < 0)
		return (ft_error(4));
	args->max_meal = -1;
	if (argv[5])
	{
		args->max_meal = ft_atoi(argv[5]);
		if (args->max_meal < 1)
			return (ft_error(4));
	}
	args->first_time = ft_get_time();
	args->die = 0;
	args->meal_finished = 0;
	return (0);
}

static int	ft_mutex_init(t_args *args)
{
	int	i;

	i = 0;
	args->forks = malloc(sizeof(pthread_mutex_t) * args->nb_philo);
	if (!args->forks)
		return (ft_error(99));
	while (i < args->nb_philo)
		if (pthread_mutex_init(&args->forks[i++], NULL))
			return (ft_error(6));
	if (pthread_mutex_init(&args->block, NULL))
		return (ft_error(6));
	if (pthread_mutex_init(&args->printing, NULL))
		return (ft_error(6));
	return (0);
}

static int	ft_philos_init(t_args *args)
{
	int		i;

	args->philos = malloc(sizeof(t_philo) * args->nb_philo);
	if (!args->philos)
		return (ft_error(99));
	i = -1;
	while (++i < args->nb_philo)
	{
		args->philos[i] = malloc(sizeof(t_philo));
		if (!args->philos[i])
			return (ft_error(99));
		args->philos[i]->rules = args;
		args->philos[i]->nb = i;
		args->philos[i]->left_fork = i;
		args->philos[i]->right_fork = (i + 1) % args->nb_philo;
		args->philos[i]->last_meal = args->first_time;
		args->philos[i]->nb_meal = 0;
	}
	return (0);
}

int	ft_init_all(t_args *args, char **argv)
{
	if (ft_struct_init(args, argv))
		return (1);
	if (ft_mutex_init(args))
		return (1);
	if (ft_philos_init(args))
		return (1);
	return (0);
}
