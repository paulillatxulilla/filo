/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:03:06 by padan-pe          #+#    #+#             */
/*   Updated: 2025/09/30 15:59:42 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int ft_checknum(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    if (ft_atoi(str) == -1)
    {
        if (str[i] == '0' && i == 0)
            return (1);
        else
            return (0);
    }
    return (1);
}

int ft_parse_args(char **argv)
{
    if (ft_atoi(argv[1]) == -1|| ft_atoi(argv[2]) == -1|| ft_atoi(argv[3]) == -1
	|| ft_atoi(argv[4]) == -1)
	{
		printf("Error en argumentos\n");
	    return (0);
	}
    if (argv[5] != NULL && ft_checknum(argv[5]) == 0)
	{
		printf("Error en argumentos\n");
	    return (0);
	}
    return (1);
}
