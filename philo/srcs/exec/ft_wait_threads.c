/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:24:31 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 20:44:42 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait_threads(t_args *args)
{
	t_philo	**philos;
	int		i;

	philos = args->philos;
	pthread_mutex_lock(&args->block);
	args->die = 1;
	pthread_mutex_unlock(&args->block);
	i = -1;
	while (++i < args->nb_philos)
	{
		pthread_mutex_lock(&args->block);
		philos[i]->is_dead = 1;
		pthread_mutex_unlock(&args->block);
	}
	i = -1;
	while (++i < args->nb_philos)
		pthread_join(philos[i]->thread, NULL);
	i = -1;
	while (++i < args->nb_philos)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->block);
	pthread_mutex_destroy(&args->printing);
}
