/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:46:23 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/30 18:02:28 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filo.h"

void	hmm(t_philo *philo)
{
	ft_printf("hmmmmmmmmmm (pensando)", philo, philo->id);
}

void	zzz(t_philo *philo)
{
	ft_printf("zzzzzzzzzzzz (durmiendo)", philo, philo->id);
	usleep(philo->time_to_sleep);
}

void	ñam(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	ft_printf("ha cogido un tenedor", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->fork);
		return ;
	}
	pthread_mutex_lock(philo->o_fork);
	ft_printf("ha cogido otro tenedor", philo, philo->id);
	philo->eating = 1;
	ft_printf("ñam ñam ñam (comiendo)", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = ft_time();
	philo->meals_eaten++;
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->o_fork);
}