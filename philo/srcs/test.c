/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:31:59 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/12 11:47:10 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define INITIAL_STOCK 20

typedef struct
{
	int stock;

	pthread_t thread_store;
	pthread_t thread_clients;

	pthread_mutex_t mutex_stock;
}	store_t;

static store_t store =
{
   .stock = INITIAL_STOCK,
};

static int get_random (int max)
{
   double val;

   val = (double) max * rand ();
   val = val / (RAND_MAX + 1.0);

   return ((int) val);
}

void	*ft_store(void *p_data)
{
	while (1)
	{
		pthread_mutex_lock(&store.mutex_stock);
		if (store.stock <= 0)
		{
			store.stock = INITIAL_STOCK;
			printf("fill-up the store\n");
		}			
		pthread_mutex_unlock(&store.mutex_stock);
	}
	(void)p_data;
	return (NULL);
}

void	*ft_client(void *p_data)
{
	int ran;

	while (1)
	{
		pthread_mutex_lock(&store.mutex_stock);
		
		ran = get_random(5);	
		sleep(get_random(5));
		store.stock -= ran;
		printf("take %d item !\n", ran);

		pthread_mutex_unlock(&store.mutex_stock);
	}
	(void)p_data;
	return (NULL);
}

int	main(int argc, char **argv)
{
	int ret;
	pthread_t	thrd_store;
	printf("Creer un thread !\n");
	ret = pthread_create(&thrd_store, NULL, ft_store, NULL);
	pthread_t	thrd_client;
	if (ret == 0)
	{
		ret = pthread_create(&thrd_client, NULL, ft_client, NULL);

		if (ret)
			return (0);
	}
	else
		return (0);

	pthread_join(thrd_client, NULL);
	pthread_join(thrd_store, NULL);


	(void)argc;
	(void)argv;
}
