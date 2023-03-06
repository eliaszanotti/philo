/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:32:51 by elias             #+#    #+#             */
/*   Updated: 2023/03/06 19:34:30 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

struct	s_philo;

typedef struct s_args
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	block;
	pthread_mutex_t	printing;
	struct s_philo	**philos;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_meal;
	long long		first_time;
	int				die;
}	t_args;

typedef struct s_philo
{
	t_args		*rules;
	pthread_t	thread;
	int			nb;
	int			left_fork;
	int			right_fork;
	long long	last_meal;
	int			nb_meal;
	int			is_dead;
}	t_philo;

// ft_atoi.c
int			ft_atoi(const char *str);
// ft_error.c
int			ft_error(int error_code);
int			ft_argv_checker(char **argv);
void		ft_print_info(t_philo *philo, char *str);
// ft_launch_philos.c
int			ft_launch_philos(t_args *args);
//	ft_init_all.c
int			ft_init_all(t_args *args, char **argv);
// ft_time_utils.c
long long	ft_get_time(void);
long long	ft_diff(long long start, long long end);
// ft_waits.c
int			ft_wait_death(t_args *args);
void		ft_wait_threads(t_args *args, t_philo **p);

void		*ft_born(t_philo *philo);

int			ft_start_execution(t_args *args);

#endif
