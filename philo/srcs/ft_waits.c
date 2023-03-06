/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias </var/spool/mail/elias>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:25:43 by elias             #+#    #+#             */
/*   Updated: 2023/03/06 18:31:03 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	ft_wait_threads(t_args *args, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < args->nb_philos)
		pthread_join(philos[i]->thread, NULL);
	i = -1;
	while (++i < args->nb_philos)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->block);
	pthread_mutex_destroy(&args->printing);
}
