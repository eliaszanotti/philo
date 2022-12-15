/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:23:30 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/14 15:28:25 by event01          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philos_init(t_args *args, t_philo **philos)
{
	int		i;

	i = -1;
	while (++i < args->nb_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (9);
		philos[i]->rules = args;
		philos[i]->nb = i;
		philos[i]->left_fork = i;
		philos[i]->right_fork = (i + 1) % args->nb_philo;
		philos[i]->last_meal = args->first_time;
	}
	return (0);
}

int	ft_struct_init(t_args *args, char **argv)
{
	args->nb_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]) * 1000;
	args->time_to_eat = ft_atoi(argv[3]) * 1000;
	args->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (args->nb_philo < 1 || args->nb_philo > 256 || args->time_to_die < 0 \
			|| args->time_to_eat < 0 || args->time_to_sleep < 0)
		return (3);
	args->nb_meal = 0;
	if (argv[5])
	{
		args->nb_meal = ft_atoi(argv[5]);
		if (args->nb_meal < 1)
			return (3);
	}
	args->first_time = ft_get_time();
	args->die = 0;
	return (0);
}
