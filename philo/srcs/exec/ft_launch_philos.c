/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:10:51 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 19:04:27 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_launch_philos(t_args *args)
{
	t_philo	**philos;
	int		i;

	philos = args->philos;
	i = -1;
	while (++i < args->nb_philos)
		if (pthread_create(&philos[i]->thread, NULL, (void *)ft_born, philos[i]))
			return (ft_error(5));
	return (0);
}
