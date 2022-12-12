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

typedef struct s_args
{
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_meal;
	pthread_t	*philosophers;
	int			nb_forks;
	int			actual;
}	t_args;

int	ft_atoi(const char *str);
t_args	*ft_struct_init(char **argv, int argc);

#endif
