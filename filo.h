/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:09:30 by padan-pe          #+#    #+#             */
/*   Updated: 2025/10/14 17:13:08 by padan-pe         ###   ########.fr       */
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
	size_t			start_time;
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
	pthread_mutex_t	*forks;
}					t_pilot;

int		ft_atoi(const char	*str);
int		ft_checknum(char *str);
int		ft_isdigit(char *arg);
int		ft_parse_args(char **argv);
void	ft_create_thread(t_pilot *pilot);
void	*ft_routine(void	*pointer);
void	ft_asign_general(t_philo *philo, char **argv);
void	ft_asign_pilot(t_pilot *pilot, char **argv);
void	ft_asign_philo(t_pilot *pilot, char **argv);
int		ft_death_flag_check(t_philo *philo);
size_t	ft_time(void);
void	ft_printf(char *str, t_philo *philo, int id);
void	hmm(t_philo *philo);
void	zzz(t_philo *philo);
void	nyam(t_philo *philo);
void	*ft_monitor_routine(void *pointer);
int		ft_eaten(t_philo *philo);
int		ft_dead(t_philo *philo);
int		ft_death_check(t_philo *philo);
void	ft_kill(t_pilot *pilot);
int		ft_usleep(size_t mili);
void	ft_lefthanded(t_philo *philo);
#endif