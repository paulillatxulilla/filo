/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:56:04 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/17 17:50:57 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void ft_create_thread(t_pilot	*pilot)
{
    int i;
	
    i = 0;
    while(pilot->philo->num_of_philos > i)
    {
        if (pthread_create(&pilot->philo[i].thread, NULL, &ft_routine, &pilot->philo) != 0 ||
		pthread_join(pilot->philo[i].thread, NULL) != 0)
		{
			printf("Error en la creación de filósofos");
			exit(1);
		}
        i++;
		pilot->philo->id++;
    }
}

void	*ft_routine(void	*philo)
{
	t_philo *philoo;
	philoo = (t_philo *)philo;
	printf("id = %d", philoo->id);
	return (0);
}

/* int	time ()//asi se miden los microsegundos 
{
	struct timeval start;
	struct timeval end;
	long mls;
	long s;
	long total;
	
	mls = 0;
	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	s = end.tv_sec - start.tv_sec;
	mls = end.tv_usec - start.tv_usec;
	total = (s * 1000000) + mls;
	
	}
	*/
//◦ timestamp_in_ms X has taken a fork
//◦ timestamp_in_ms X is eating
//◦ timestamp_in_ms X is sleeping
//◦ timestamp_in_ms X is thinking
//◦ timestamp_in_ms X died