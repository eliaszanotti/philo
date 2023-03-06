/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:06:49 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/06 12:06:52 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_error_range_1(int error_code)
{
	if (error_code == 2)
		printf("Wrong amount of arguments\n");
	else if (error_code == 3)
		printf("Arguments are not valid integers\n");
	else if (error_code == 4)
		printf("Incorrect arguments (max number of philosophers is 256)\n");
	else if (error_code == 5)
		printf("Impossible to create threads\n");
	else if (error_code == 6)
		printf("Mutex cannot be initialized\n");
	return (1);
}

int	ft_error(int error_code)
{
	if (error_code)
		printf("\e[1;31m[ERROR:%d]\e[0m ", error_code);
	if (error_code < 10)
		return (ft_error_range_1(error_code));
	else if (error_code == 99)
		printf("Malloc cannot be created\n");
	else
		printf("Undefined\n");
	return (1);
}
