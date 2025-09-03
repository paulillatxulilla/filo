/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:09:26 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/03 15:53:06 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int main(int argc, char *argv)
{
    if (argc != 7 || argc != 6)
        return (0);
    if (ft_atoi(argv[1]) == -1|| ft_atoi(argv[2]) == -1
        || ft_atoi(argv[3]) == -1|| ft_atoi(argv[4]) == -1 || ft_atoi(argv[5]) == -1)
        return (0);
    if (argv[6] && ft_atoi(argv[6]) == -1)    
        return (0);
    //argv[1] = n de filosofos
    //argv[2] = tiempo para morir (tienen que comer antes de ese tiempo)
    //argv[3] = tiempo para comer (lo que tardan en  comer)
    //argv[4] = tiempo para dormir (lo que tardan en  dormir)
    //argv[5] = tiempo para dormir (lo que tardan en  dormir)
    //argv[6] = veces que tienen que comer para terminar (opcional) (si no se especifica, hasta que uno se muera)
	//timestamp_in_ms X has taken a fork
	//◦ timestamp_in_ms X is eating
	//◦ timestamp_in_ms X is sleeping
	//◦ timestamp_in_ms X is thinking
	//◦ timestamp_in_ms X died
	//no puede pasar mucho tiempo desde que se muere un filosofo y sale que ha muerto (10 mls)
    
}