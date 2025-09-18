/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:09:26 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/18 19:14:37 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int main(int argc, char **argv)
{
	t_pilot	pilot;

	if (argc < 5 || argc > 6)
	return (0);
	if (argv[5] && ft_checknum(argv[5]) == 1)
	return (0);
	if (ft_atoi(argv[1]) == -1|| ft_atoi(argv[2]) == -1|| ft_atoi(argv[3]) == -1
	|| ft_atoi(argv[4]) == -1)
	return (0);
	pilot.philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	ft_asign(pilot.philo, argv);
    ft_create_thread(&pilot);
    return (0);
    //argv[1] = n de filosofos
    //argv[2] = tiempo para morir (tienen que comer antes de ese tiempo)
    //argv[3] = tiempo para comer (lo que tardan en  comer)
    //argv[4] = tiempo para dormir (lo que tardan en  dormir)
    //argv[5] = veces que tienen que comer para terminar (opcional) (si no se especifica, hasta que uno se muera)
	//no puede pasar mucho tiempo desde que se muere un filosofo y sale que ha muerto (10 mls)
}

int ft_checknum(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    if (ft_atoi(str) == -1)
    {
        if (str[i] == '0' && i == 0)
            return (0);
        else
            return (1);
    }
    return (0);
}

void	ft_asign(t_philo *philo, char **argv)
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