/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:00:27 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/19 18:02:47 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void    ft_asign_pilot(t_pilot *pilot, char **argv)
{
    pilot->philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
    pilot->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
    pilot->dead_flag = 0;
    pthread_mutex_init(&pilot->write_lock, NULL);
	pthread_mutex_init(&pilot->dead_lock, NULL);
	pthread_mutex_init(&pilot->meal_lock, NULL);
}

void    ft_asign_philo(t_pilot *pilot, char **argv)
{
	int i;
	
    i = 0;
    while (ft_atoi(argv[1]) > i)
    {
		ft_asign_general(&pilot->philo[i], argv);
        pilot->philo[i].id = i + 1;
        pilot->philo[i].eating = 0;
        pilot->philo[i].meals_eaten = 0;
        pilot->philo[i].start_time = //funcion para el tiempo;
        pilot->philo[i].last_meal = //funcion para el tiempo;
        pilot->philo[i].write_lock = &pilot->write_lock;
        pilot->philo[i].dead_lock = &pilot->dead_lock;
        pilot->philo[i].meal_lock = &pilot->meal_lock;
        pilot->philo[i].dead = &pilot->dead_flag;
        pilot->philo[i].fork = &pilot->forks[i];
        if (i == 0)
		pilot->philo->o_fork = &pilot->forks[ft_atoi(argv[1]) - 1];
        else
            pilot->philo->o_fork = &pilot->forks[i - 1];
			i++;
		}
	}
	
void	ft_asign_general(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}