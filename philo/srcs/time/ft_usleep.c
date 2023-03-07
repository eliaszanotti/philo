/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:48:33 by elias             #+#    #+#             */
/*   Updated: 2023/03/07 15:13:11 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_get_usleep_time(void)
{
	struct timeval	time;
	size_t			total;

	gettimeofday(&time, NULL);
	total = time.tv_sec;
	total *= 1000000;
	total += time.tv_usec;
	return (total);
}

void	ft_usleep(size_t time)
{
	size_t	first_time;
	size_t	end_time;

	first_time = ft_get_usleep_time();
	end_time = first_time + time - 1;
	while (first_time < end_time)
	{
		first_time = ft_get_usleep_time();
		usleep(10);
	}
}
