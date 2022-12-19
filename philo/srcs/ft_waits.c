/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias </var/spool/mail/elias>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:25:43 by elias             #+#    #+#             */
/*   Updated: 2022/12/19 16:59:52 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait_death(t_args *args, t_philo **p)
{
	int			i;

	while (args->meal_finished == 0)
	{
		i = -1;
		while (++i < args->nb_philo && !args->die)
		{
			pthread_mutex_lock(&args->block);
			if (ft_diff(p[i]->last_meal, ft_get_time()) > args->time_to_die)
			{
				ft_print_info(p[i], "died");
				args->die = 1;
			}
			pthread_mutex_unlock(&args->block);
			usleep(100);
		}
		if (args->die)
			break ;
		i = 0;
		while (args->max_meal != -1 && i < args->nb_philo && \
				p[i]->nb_meal >= args->max_meal - 1)
			i++;
		if (i == args->nb_philo)
			args->meal_finished = 1;
	}
}

void	ft_wait_threads(t_args *args, t_philo **philos)
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
