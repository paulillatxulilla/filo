/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:09:26 by padan-pe          #+#    #+#             */
/*   Updated: 2025/10/14 17:11:45 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	main(int argc, char **argv)
{
	t_pilot	pilot;

	if (argc < 5 || argc > 6)
	{
		printf("Error en argumentos");
		return (0);
	}
	if (ft_parse_args(argv) == 0)
		return (0);
	ft_asign_pilot(&pilot, argv);
	ft_asign_philo(&pilot, argv);
	ft_create_thread(&pilot);
	ft_kill(&pilot);
	return (0);
}
