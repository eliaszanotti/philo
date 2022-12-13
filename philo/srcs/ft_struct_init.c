/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:23:30 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/12 19:09:45 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philos_init(t_args *args)
{
	int		i;

	i = -1;
	while (i++ < args->nb_philo)
	{
		args->philos[i].nb = i;
	}
	return (0);
}

int	ft_struct_init(t_args *args, char **argv)
{
	args->nb_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
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
	args->philos = malloc(sizeof(t_philo) * args->nb_philo);
	if (!args->philos)
		return (9);
	ft_philos_init(args);
	args->nb_forks = args->nb_philo;
	return (0);
}
