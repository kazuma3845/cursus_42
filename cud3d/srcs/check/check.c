/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:35 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/26 14:32:00 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_char(t_map *lst, int i)
{
	int	col;
	int	num;

	num = 0;
	while (lst->map[++i])
	{
		col = 0;
		while (lst->map[i][col])
		{
			if (lst->map[i][col] == 'N' || lst->map[i][col] == 'S'
				|| lst->map[i][col] == 'E' || lst->map[i][col] == 'W')
			{
				num++;
				col++;
			}
			else if (lst->map[i][col] == '0' || lst->map[i][col] == '1'
				|| lst->map[i][col] == 'P' || lst->map[i][col] == ' '
				|| lst->map[i][col] == '\n')
				col++;
			else
				return (true);
		}
	}
	return (num != 1);
}

bool	check_vide(t_map *lst)
{
	int	i;
	int	col;
	int	count;
	int	num;

	i = -1;
	num = 1;
	while (lst->map[++i])
	{
		col = -1;
		count = 0;
		while (lst->map[i][++col])
			if (lst->map[i][col] == '0' || lst->map[i][col] == '1'
				|| lst->map[i][col] == 'N' || lst->map[i][col] == 'S'
				|| lst->map[i][col] == 'E' || lst->map[i][col] == 'W'
				|| lst->map[i][col] == 'P')
				count++;
		if (num == 0 && count != 0)
			return (true);
		if (num != count)
			num = count;
	}
	return (false);
}

bool	touch_zero(t_map *lst, int line, int col)
{
	if ((lst->map[line][col + 1] == '0' || lst->map[line][col + 1] == '1'
			|| lst->map[line][col + 1] == 'N' || lst->map[line][col + 1] == 'S'
			|| lst->map[line][col + 1] == 'E' || lst->map[line][col + 1] == 'W'
			|| lst->map[line][col + 1] == 'P')
		&& (lst->map[line + 1][col] == '0' || lst->map[line + 1][col] == '1'
			|| lst->map[line + 1][col] == 'N' || lst->map[line + 1][col] == 'S'
			|| lst->map[line + 1][col] == 'E' || lst->map[line + 1][col] == 'W'
			|| lst->map[line + 1][col] == 'P')
		&& (lst->map[line][col - 1] == '0' || lst->map[line][col - 1] == '1'
			|| lst->map[line][col - 1] == 'N' || lst->map[line][col - 1] == 'S'
			|| lst->map[line][col - 1] == 'E' || lst->map[line][col - 1] == 'W'
			|| lst->map[line][col - 1] == 'P')
		&& (lst->map[line - 1][col] == '0' || lst->map[line - 1][col] == '1'
			|| lst->map[line - 1][col] == 'N' || lst->map[line - 1][col] == 'S'
			|| lst->map[line - 1][col] == 'E' || lst->map[line
			- 1][col] == 'W' || lst->map[line - 1][col] == 'P'))
		return (false);
	return (true);
}

bool	check_wall(t_map *lst)
{
	int	col;
	int	line;

	line = -1;
	while (lst->map[++line])
	{
		col = 0;
		while (lst->map[line][col])
		{
			if (lst->map[line][col] == '0' && touch_zero(lst, line, col))
				return (true);
			if (lst->map[line][col] == 'N' && touch_zero(lst, line, col))
				return (true);
			if (lst->map[line][col] == 'S' && touch_zero(lst, line, col))
				return (true);
			if (lst->map[line][col] == 'E' && touch_zero(lst, line, col))
				return (true);
			if (lst->map[line][col] == 'W' && touch_zero(lst, line, col))
				return (true);
			if (lst->map[line][col] == 'P' && touch_zero(lst, line, col))
				return (true);
			col++;
		}
	}
	return (false);
}
