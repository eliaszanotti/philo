/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:51:26 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/12 19:15:08 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	**philos;
	int		error_code;

	if (argc != 5 && argc != 6)
		return (ft_error(1));
	error_code = ft_argv_checker(argv + 1);
	if (error_code)
		return (ft_error(error_code));
	error_code = ft_struct_init(&args, argv);
	if (error_code)
		return (ft_error(error_code));
	philos = malloc(sizeof(t_philo) * args.nb_philo);
	if (!philos)
		return (ft_error(9));
	error_code = ft_philos_init(&args, philos);
	if (error_code)
		return (ft_error(error_code));
	error_code = ft_launch_philos(&args, philos);
	if (error_code)
		return (ft_error(error_code));
}
