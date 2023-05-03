/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:48:33 by elias             #+#    #+#             */
/*   Updated: 2023/05/03 12:41:58 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	long int	new_time;

	time = time / 1000;
	new_time = ft_get_time();
	while (ft_get_time() - new_time < time)
		usleep(time / 10);
}
