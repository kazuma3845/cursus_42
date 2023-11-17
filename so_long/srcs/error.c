/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:10:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/17 16:06:52 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	error_car(t_game x)
{
	t_map	car;

	car.ligne = 0;
	car.col = 0;
	car.p = 0;
	car.c = 0;
	car.e = 0;
	while (x.map[car.ligne] != NULL)
	{
		if (x.map[car.ligne][car.col] == 'P')
			car.p++;
		if (x.map[car.ligne][car.col] == 'C')
			car.c++;
		if (x.map[car.ligne][car.col] == 'E')
			car.e++;
		if (x.map[car.ligne][car.col] == '\0')
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

int	error_map(t_game x)
{
	if (error_car(x) == 1 || error_wall(x) == 1 || error_size(x) == 1)
		return (1);
	// if (error_chemin(map) == 1)
	// 	return (1);
	return (0);
}

int	error_line(t_game x)
{
	t_map	len;

	len.col = 0;
	len.ligne = 1;
	while (x.map[len.ligne][len.col] != '\0')
	{
		if (x.map[len.ligne][0] != '1' || x.map[len.ligne][ft_strlen(x.map[len.ligne])
			- 2] != '1')
			return (1);
		if (x.map[len.ligne][len.col] == '\n')
		{
			len.ligne++;
			len.col = 0;
		}
		len.col++;
	}
	len.col = 0;
	while (x.map[len.ligne][len.col] != '\0')
	{
		if (x.map[len.ligne][len.col] != '1')
			return (1);
		len.col++;
	}
	x.y = len.ligne;
	return (0);
}

int	error_wall(t_game x)
{
	t_map	len;

	len.col = 0;
	while (x.map[0][len.col] != '\n')
	{
		if (x.map[0][len.col] != '1')
			return (1);
		len.col++;
	}
	x.x = len.col;
	if (error_line(x) == 1)
		return (1);
	return (0);
}

int	error_size(t_game x)
{
	t_map	len;

	len.col = 0;
	len.ligne = 0;
	if (ft_strlen(x.map[0]) < 5)
		return (1);
	while (x.map[len.ligne] != NULL)
	{
		if ((x.map[len.ligne][len.col] == '\n' && len.col != (ft_strlen(x.map[0])
				- 1)) || (x.map[len.ligne][len.col] == '\0'
				&& len.col != (ft_strlen(x.map[0]) - 1)))
			return (1);
		if (x.map[len.ligne][len.col] == '\0' || x.map[len.ligne][len.col] == '\n')
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
