/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:23 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 18:34:07 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_dead(t_args *args, t_philo *philo)
{
	if (ft_diff(philo->last_meal, ft_get_time()) > args->time_to_die)
		return (1);
	return (0);
}

static int	ft_check_each_philos(t_args *args, int *nb_finished_meal)
{
	t_philo	**philos;
	int		i;

	philos = args->philos;
	i = -1;
	while (++i < args->nb_philos)
	{
		if (ft_is_dead(args, philos[i]))
		{
			ft_print_info(philos[i], "died");
			args->die = 1;
			return (1);
		}
		if (philos[i]->nb_meal >= args->min_meal)
			*nb_finished_meal += 1;
	}
	return (0);
}

int	ft_wait_death(t_args *args)
{
	int		nb_finished_meal;

	while (1)
	{
		nb_finished_meal = 0;
		usleep(100);
		pthread_mutex_lock(&args->block);
		if (ft_check_each_philos(args, &nb_finished_meal))
		{
			pthread_mutex_unlock(&args->block);
			return (0);
		}
		pthread_mutex_unlock(&args->block);
		if (nb_finished_meal == args->nb_philos)
			return (0);
	}
	return (0);
}
