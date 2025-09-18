/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:56:04 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/18 19:13:39 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void ft_create_thread(t_pilot	*pilot)
{
    int i;
	
    i = 0;
	pilot->philo->id = 1;
    while(pilot->philo->num_of_philos > i)
    {
        if (pthread_create(&pilot->philo[i].thread, NULL, &ft_routine, pilot->philo) != 0 ||
		pthread_join(pilot->philo[i].thread, NULL) != 0)
		{
			printf("Error en la creación de filósofos");
			exit(1);
		}
        i++;
		pilot->philo->id++;
    }
	pthread_mutex_init(pilot->philo->fork, NULL);
	pthread_mutex_init(pilot->philo->o_fork, NULL);
	
}

void	*ft_routine(void	*philo)
{
	t_philo *philoo;
	struct timeval start;
	struct timeval end;
	long mls;
	philoo = (t_philo *)philo;
	mls = 0;
	gettimeofday(&start, NULL);
	if (philoo->time_to_die > start.tv_usec)
		return (NULL);
	if (philoo->fork && philoo->o_fork)
	{
		pthread_mutex_lock(philoo->fork);
		pthread_mutex_lock(philoo->o_fork);
		gettimeofday(&end, NULL);
	}
}
	// mls = end.tv_usec - start.tv_usec;

	//https://github.com/DeRuina/philosophers/tree/main/src

	

/* int	time ()//asi se miden los microsegundos 
{

	
	mls = 0;
	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	s = end.tv_sec - start.tv_sec;
	total = (s * 1000000) + mls;
	
	}
	*/
//◦ timestamp_in_ms X has taken a fork
//◦ timestamp_in_ms X is eating
//◦ timestamp_in_ms X is sleeping
//◦ timestamp_in_ms X is thinking
//◦ timestamp_in_ms X died