/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:56:04 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/08 18:36:48 by padan-pe         ###   ########.fr       */
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
        if (pthread_create(&th[i], NULL, &ft_routine, NULL) != 0 ||
		pthread_join(th[i], NULL) != 0)
		{
			printf("Error en la creación de filósofos");
			exit(1);	
		}
        i++;
    }
}

void	*ft_routine()
{
	printf("hilo bien impreso\n");
	return (0);
}