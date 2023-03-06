/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event01 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:40:17 by event01           #+#    #+#             */
/*   Updated: 2022/12/19 16:48:33 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

long long	ft_diff(long long start, long long end)
{
	return (end - start);
}
