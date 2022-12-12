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

t_args	*ft_struct_init(char **argv, int argc)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->nb_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->nb_meal = 0;
	if (argc == 6)
		args->nb_meal = ft_atoi(argv[5]);
	args->philosophers = malloc(sizeof(pthread_t) * args->nb_philo);
	args->nb_forks = args->nb_philo;
	args->actual = -1;
	return (args);
}
