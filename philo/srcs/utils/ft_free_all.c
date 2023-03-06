/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:31:25 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 20:47:48 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_args *args)
{
	t_philo	**philos;
	int		i;

	philos = args->philos;
	i = -1;
	while (++i < args->nb_philos)
		free(philos[i]);
	free(philos);
	free(args->forks);	
}
