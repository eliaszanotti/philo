/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:51:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 12:03:27 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	error_code = ft_launch_philos(&args, args.philos);
	if (error_code)
		return (ft_error(error_code));
}
