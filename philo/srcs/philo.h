/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:35:39 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/14 14:29:36 by event01          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/time.h>

typedef struct s_args
{
	struct s_philo		*philos;
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_meal;
	long long	first_time;
	int			*forks;
}	t_args;

typedef struct s_philo
{
	t_args	*rules;
	pthread_t	thread;
	int			nb;
	int			left_fork;
	int			right_fork;
}	t_philo;

// ft_atoi.c
int	ft_atoi(const char *str);
// ft_error.c
int	ft_error(int error_code);
int	ft_argv_checker(char **argv);
// ft_launch_philos.c
int	ft_launch_philos(t_args *args);
// ft_struct_init.c
int	ft_struct_init(t_args *args, char **argv);
// ft_time_utils.c
long long	ft_get_time(void);
long long	ft_time_diff(long long start, long long end);

#endif
