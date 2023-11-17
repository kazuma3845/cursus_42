/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:10:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/17 14:18:32 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	error_car(char **map)
{
	t_map	car;

	car.ligne = 0;
	car.col = 0;
	car.p = 0;
	car.c = 0;
	car.e = 0;
	while (map[car.ligne] != NULL)
	{
		if (map[car.ligne][car.col] == 'P')
			car.p++;
		if (map[car.ligne][car.col] == 'C')
			car.c++;
		if (map[car.ligne][car.col] == 'E')
			car.e++;
		if (map[car.ligne][car.col] == '\0')
		{
			car.ligne++;
			car.col = 0;
		}
		car.col++;
	}
	if (car.p != 1 || car.e != 1 || car.c < 1)
		return (1);
	return (0);
}

int	error_map(char **map)
{
	if (error_car(map) == 1 || error_wall(map) == 1 || error_size(map) == 1)
		return (1);
	// if (error_chemin(map) == 1)
	// 	return (1);
	return (0);
}

int	error_line(char **map)
{
	t_map	len;

	len.col = 0;
	len.ligne = 1;
	while (map[len.ligne][len.col] != '\0')
	{
		if (map[len.ligne][0] != '1' || map[len.ligne][ft_strlen(map[len.ligne])
			- 2] != '1')
			return (1);
		if (map[len.ligne][len.col] == '\n')
		{
			len.ligne++;
			len.col = 0;
		}
		len.col++;
	}
	len.col = 0;
	while (map[len.ligne][len.col] != '\0')
	{
		if (map[len.ligne][len.col] != '1')
			return (1);
		len.col++;
	}
	return (0);
}

int	error_wall(char **map)
{
	t_map	len;

	len.col = 0;
	while (map[0][len.col] != '\n')
	{
		if (map[0][len.col] != '1')
			return (1);
		len.col++;
	}
	if (error_line(map) == 1)
		return (1);
	return (0);
}

int	error_size(char **map)
{
	t_map	len;

	len.col = 0;
	len.ligne = 0;
	if (ft_strlen(map[0]) < 5)
		return (1);
	while (map[len.ligne] != NULL)
	{
		if ((map[len.ligne][len.col] == '\n' && len.col != (ft_strlen(map[0])
				- 1)) || (map[len.ligne][len.col] == '\0'
				&& len.col != (ft_strlen(map[0]) - 1)))
			return (1);
		if (map[len.ligne][len.col] == '\0' || map[len.ligne][len.col] == '\n')
		{
			len.ligne++;
			len.col = 0;
		}
		len.col++;
	}
	if (len.ligne < 3)
		return (1);
	return (0);
}
