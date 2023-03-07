/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:32:51 by elias             #+#    #+#             */
/*   Updated: 2023/03/07 15:13:27 by elias            ###   ########.fr       */
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

//	EXEC
void		*ft_born(t_philo *philo);
int			ft_launch_philos(t_args *args);
int			ft_start_execution(t_args *args);
int			ft_wait_death(t_args *args);
void		ft_wait_threads(t_args *args);
//	PARSING
int			ft_argv_checker(char **argv);
//	TIME
long long	ft_diff(long long start, long long end);
long long	ft_get_time(void);
void		ft_usleep(size_t sleep);
//	UTILS
int			ft_atoi(const char *str);
int			ft_error(int error_code);
void		ft_free_all(t_args *args);
int			ft_init_all(t_args *args, char **argv);
int			ft_is_dead(t_args *args, t_philo *philo);
void		ft_print_info(t_philo *philo, char *str);

#endif
