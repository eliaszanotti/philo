/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:52:33 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 20:52:45 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_args *args, t_philo *philo)
{
	long long	diff;

	diff = ft_diff(philo->last_meal, ft_get_time());
	if (diff > args->time_to_die)
		return (1);
	return (0);
}
