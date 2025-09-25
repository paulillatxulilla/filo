/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:00:32 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/25 19:23:37 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filo.h"

int	ft_death_check(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if ((ft_time() - philo->last_meal) >= philo->time_to_die
	&& philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	ft_dead(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo[0].num_of_philos)
	{
		if (ft_death_check(&philo[i]) == 1)
		{
			ft_printf("ha muerto", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[i].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[i].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_eaten(t_philo *philo)
{
	int i;
	int ate;

	i = 0;
	ate = 0;
	if (philo[0].num_times_to_eat == -1)
		return (0);
	while (i < philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].num_times_to_eat)
			ate++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (ate == philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*ft_monitor_routine(void *pointer)
{
	t_philo *philo;

	philo = (t_philo *)pointer;
	while (1)
		if(ft_eaten(philo) == 1 || ft_dead(philo) == 1)
			break ;
	return (pointer);
}