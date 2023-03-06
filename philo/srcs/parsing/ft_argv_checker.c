/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:34:57 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 11:40:10 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_argv_checker(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (ft_error(3));
	}
	return (0);
}
