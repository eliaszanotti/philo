/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias </var/spool/mail/elias>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:25:43 by elias             #+#    #+#             */
/*   Updated: 2022/12/19 16:31:04 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_wait_death(t_args *args, t_philo **philos)
{
	long long	time_diff;
	int	i;

	while (args->meal_finished == 0)
	{
		i = -1;
		while (++i < args->nb_philo && !args->die)
		{
			pthread_mutex_lock(&args->block);
			time_diff = ft_time_diff(philos[i]->last_meal, ft_get_time());
			if (time_diff > args->time_to_die)
			{
				ft_print_info(philos[i], "died");
				args->die = 1;
			}
			pthread_mutex_unlock(&args->block);
			usleep(100);
		}
		if (args->die)
			break ;
		i = 0;
		while (args->max_meal != -1 && i < args->nb_philo && \
				philos[i]->nb_meal >= args->max_meal) // TODO 11 meal eated when args[5] = 10 
			i++;
		if (i == args->nb_philo)
			args->meal_finished = 1;
	}
}

void	ft_wait_threads(t_args *args, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < args->nb_philo)
		pthread_join(philos[i]->thread, NULL);
	i = -1;
	while (++i < args->nb_philo)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->block);
	pthread_mutex_destroy(&args->printing);
}
