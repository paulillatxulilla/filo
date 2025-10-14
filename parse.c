/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:03:06 by padan-pe          #+#    #+#             */
/*   Updated: 2025/10/14 16:30:52 by padan-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	ft_checknum(char *str)//para parsear el 5º argumento
{
	int	i;

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

int	ft_isdigit(char *arg)//parsear letras en números
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < 48 || arg[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_args(char **argv)//parsear argumentos
{
	if (ft_isdigit(argv[1]) == 0 || ft_isdigit(argv[2]) == 0
		|| ft_isdigit(argv[3]) == 0 || ft_isdigit(argv[4]) == 0)
	{
		printf("Error en argumentos\n");
		return (0);
	}
	if (ft_atoi(argv[1]) == -1 || ft_atoi(argv[2]) == -1
		|| ft_atoi(argv[3]) == -1 || ft_atoi(argv[4]) == -1)
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
