/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:51:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 12:24:42 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_launch_philos(t_args *args, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < args->nb_philo)
		if (pthread_create(&philos[i]->thread, NULL, ft_born, philos[i]))
			return (ft_error(5));
	ft_wait_death(args, philos);
	ft_wait_threads(args, philos);
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;
	int		error_code;

	if (argc != 5 && argc != 6)
		return (ft_error(2));
	if (ft_argv_checker(argv + 1))
		return (1);
	if (ft_init_all(&args, argv))
		return (1);
	if (ft_launch_philos(&args, args.philos))
		return (1);
}
