/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:46:23 by padan-pe          #+#    #+#             */
/*   Updated: 2025/10/14 16:28:26 by padan-pe         ###   ########.fr       */
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
	ft_usleep(philo->time_to_sleep);
}

void	ft_lefthanded(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork);
		ft_printf("ha cogido un tenedor", philo, philo->id);
		pthread_mutex_lock(philo->o_fork);
		ft_printf("ha cogido otro tenedor", philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->o_fork);
		ft_printf("ha cogido un tenedor", philo, philo->id);
		pthread_mutex_lock(philo->fork),
		ft_printf("ha cogido otro tenedor", philo, philo->id);
	}
}

void	nyam(t_philo *philo)
{
	if (philo->num_of_philos == 1)
	{
		pthread_mutex_lock(philo->write_lock);
		printf("0 philo 1 ha cogido un tenedor\n");
		pthread_mutex_unlock(philo->write_lock);
		ft_usleep(philo->time_to_die);
		return ;
	}
	ft_test(philo);
	philo->eating = 1;
	ft_printf("ñam ñam ñam (comiendo)", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	philo->last_meal = ft_time();
	pthread_mutex_unlock(philo->meal_lock);
	philo->eating = 0;
	ft_usleep(philo->time_to_eat);
	(pthread_mutex_unlock(philo->o_fork), pthread_mutex_unlock(philo->fork));
}
