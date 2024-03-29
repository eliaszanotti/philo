/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:22:47 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 20:43:35 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_execution(t_args *args)
{
	if (ft_launch_philos(args))
		return (1);
	if (ft_wait_death(args))
		return (1);
	ft_wait_threads(args);
	ft_free_all(args);
	return (0);
}
