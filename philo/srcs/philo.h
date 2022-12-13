/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:35:39 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/12 19:11:08 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	int			nb;
	pthread_t	thread;
}	t_philo;

typedef struct s_args
{
	t_philo		*philos;
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_meal;
	int			nb_forks;
}	t_args;

int ft_struct_init(t_args *args, char **argv);
int	ft_atoi(const char *str);
// ERROR
int	ft_error(int error_code);
int	ft_argv_checker(char **argv);

#endif
