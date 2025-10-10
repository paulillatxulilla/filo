/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:56:04 by padan-pe          #+#    #+#             */
/*   Updated: 2025/10/10 18:17:40 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void ft_create_thread(t_pilot	*pilot)
{
	pthread_t	monitor;
    int i;
    i = 0;
    if (pthread_create(&monitor, NULL, &ft_monitor_routine, pilot->philo) != 0)
		ft_kill(pilot);
	while (pilot->philo[0].num_of_philos > i)
	{
		if (pthread_create(&pilot->philo[i].thread, NULL, &ft_routine, &pilot->philo[i]) != 0)
			ft_kill(pilot);
		i++;
	}
	i = 0;
	if (pthread_join(monitor, NULL) != 0)
		ft_kill(pilot);
	while (pilot->philo[0].num_of_philos > i)
	{
		if (pthread_join(pilot->philo[i].thread, NULL) != 0)
			ft_kill(pilot);
		i++;	
	}
}

void	*ft_routine(void	*pointer)
{
	t_philo *philo;
	
	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		if (ft_death_flag_check(philo) == 0)
			ñam(philo);
		else
			break ;
		if (ft_death_flag_check(philo) == 0)	
			zzz(philo);
		else
			break ;
		if (ft_death_flag_check(philo) == 0)
			hmm(philo);
		else
		{
			ft_printf("ha muerto", philo, philo->id);
			break ;
		}
	}
	return (pointer);
}

int	ft_death_flag_check(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);		
		return(1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return(0);
}

void	ft_kill(t_pilot *pilot)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&pilot->write_lock);
	pthread_mutex_destroy(&pilot->meal_lock);
	pthread_mutex_destroy(&pilot->dead_lock);
	while(i < pilot->philo[0].num_of_philos)
	{
		pthread_mutex_destroy(&pilot->forks[i]);
		i++;
	}
}