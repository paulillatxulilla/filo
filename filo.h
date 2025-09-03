/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:09:30 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/03 15:34:35 by padan-pe         ###   ########.fr       */
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

int	ft_atoi(const char	*str)

#endif
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