/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:32:35 by padan-pe          #+#    #+#             */
/*   Updated: 2025/10/10 18:40:13 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

static int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
		return (-1);
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		i++;
		str++;
	}
	if (result > 2147483647 || i > 10 || result == 0)
		return (-1);
	return ((int)result);
}

size_t	ft_time()
{
	struct timeval	time;
	
	if (gettimeofday(&time, NULL) == -1)
		printf("Error en cálculo de tiempo\n");
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_printf(char *str, t_philo *philo, int id)
{
	size_t time;

	time = (ft_time() - philo->start_time);
	pthread_mutex_lock(philo->write_lock);
	//if (ft_death_check(philo) == 0)
		printf("%zu philo %d %s\n", time, id, str);

	//	printf("%zu philo ha muerto %d \n", time, id);
	pthread_mutex_unlock(philo->write_lock);

}

int	ft_usleep(size_t mili)
{
	size_t	start;

	start = ft_time();
	while ((ft_time() - start) < mili)
		usleep(500);
	return (0);
}