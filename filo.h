/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:09:30 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/17 18:34:31 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILO_H
# define FILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

int	ft_atoi(const char	*str);
int ft_checknum(char *str);

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	// size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*o_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_pilot
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philo;
}					t_pilot;

void ft_create_thread(t_pilot	*philo);
void	*ft_routine(void	*philo);
void	ft_asign(t_philo *philo, char **argv);

//memset = llena un espacio (str) de un carácter (c) n veces, str= hola, memset(str, x, 2), str = xxla
//printf
//malloc
//free
//write
//usleep
//gettimeofday = te dice segundos y microsegundos desde 1/1/1970 
//pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, typeof(void *(void *)) *start_routine, void *restrict arg) MIRAR HILOS
//pthread_detach
//pthread_join
// pthread_mutex_init
//pthread_mutex_destroy
//pthread_mutex_lock
//pthread_mutex_unlock
#endif