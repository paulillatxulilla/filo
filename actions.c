/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:46:23 by padan-pe          #+#    #+#             */
/*   Updated: 2025/10/10 18:23:35 by padan-pe         ###   ########.fr       */
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

void	ñam(t_philo *philo)
{
	if (philo->num_of_philos == 1)
	{
		printf("0 philo 1 ha cogido un tenedor\n");
		ft_usleep(philo->time_to_die);
		printf("%zu philo 1 ha muerto\n", philo->time_to_die);
		return ;
	}
	pthread_mutex_lock(philo->fork);
	if (ft_death_check(philo) == 0)
		ft_printf("ha cogido un tenedor", philo, philo->id);
	else
		return ;
	pthread_mutex_lock(philo->o_fork);
	if (ft_death_check(philo) == 0)
		ft_printf("ha cogido otro tenedor", philo, philo->id);
	else
		return ;
	philo->eating = 1;
	ft_printf("ñam ñam ñam (comiendo)", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	philo->last_meal = ft_time();
	pthread_mutex_unlock(philo->meal_lock);
	philo->eating = 0;
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->o_fork);
}
