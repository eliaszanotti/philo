/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:40:13 by elias             #+#    #+#             */
/*   Updated: 2023/05/12 18:01:55 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_info(t_philo *philo, char *str)
{
	long long	time_diff;
	t_args		*args;

	args = philo->rules;
	pthread_mutex_lock(&args->printing);
	time_diff = ft_diff(args->first_time, ft_get_time());
	if (!args->die)
	{
		printf("\033[1;32m%lli", time_diff);
		printf("\033[0m \033[0;33m%d\033[0m %s\n", philo->nb + 1, str);
	}
	pthread_mutex_unlock(&args->printing);
}
