/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:09:26 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/30 17:56:40 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int main(int argc, char **argv)
{
	t_pilot	pilot;
	if (argc < 5 || argc > 6)
    {
		printf("Error en argumentos");
	    return (0);
    }
	if (ft_parse_args(argv) == 0)
		return(0);
    ft_asign_pilot(&pilot, argv);
	ft_asign_philo(&pilot, argv);
    ft_create_thread(&pilot);
    ft_kill(&pilot);
    return (0);
    //argv[1] = n de filosofos
    //argv[2] = tiempo para morir (tienen que comer antes de ese tiempo)
    //argv[3] = tiempo para comer (lo que tardan en  comer)
    //argv[4] = tiempo para dormir (lo que tardan en  dormir)
    //argv[5] = veces que tienen que comer para terminar (opcional) (si no se especifica, hasta que uno se muera)
	//no puede pasar mucho tiempo desde que se muere un filosofo y sale que ha muerto (10 mls)
}
