/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:56:04 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/08 19:15:18 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void ft_create_thread(int it)
{
    int i;
    pthread_t th[it];
	
    i = 0;
    while(it > i)
    {
        if (pthread_create(&th[i], NULL, &ft_routine, &i) != 0 ||//pasarle como argumento una string que tenga en cada posicion cada n de cosas
		pthread_join(th[i], NULL) != 0)
		{
			printf("Error en la creación de filósofos");
			exit(1);	
		}
        i++;
    }
}

void	*ft_routine(void	*arg)//aqui hacer los calculos con ese n de cosas ◦ timestamp_in_ms X has taken a fork
//◦ timestamp_in_ms X is eating
//◦ timestamp_in_ms X is sleeping
//◦ timestamp_in_ms X is thinking
//◦ timestamp_in_ms X died
{
	//contador para cada uno? noentiendo
	//while (tiempo para comer no se acabe)
	//- come si puede, duerme y piensa
	//muere
	int i = *(int*) arg;
	printf("hilo %d bien impreso\n", i);
	return (0);
}