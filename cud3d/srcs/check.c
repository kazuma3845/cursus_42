/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:35 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/19 15:16:00 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_texture(t_map *lst)
{
	int		i;
	char	**str;

	i = 0;
	while (i < 6)
	{
		str = ft_split(lst->map[i], ' ');
		if (ft_strcmp(str[0], "NO") == 0)
			i++;
		else if (ft_strcmp(str[0], "SO") == 0)
			i++;
		else if (ft_strcmp(str[0], "WE") == 0)
			i++;
		else if (ft_strcmp(str[0], "EA") == 0)
			i++;
		else if (ft_strcmp(str[0], "F") == 0)
			i++;
		else if (ft_strcmp(str[0], "C") == 0)
			i++;
		else
			return (true);
		free_tab(str);
	}
	return (false);
}

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
						|| lst->map[i][col] == ' ' || lst->map[i][col] == '\n')
				col++;
			else
				return (true);
		}
	}
	if (num != 1)
		return (true);
	return (false);
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
		col = 0;
		count = 0;
		while (lst->map[i][col])
		{
			if (lst->map[i][col] == '0' || lst->map[i][col] == '1'
				|| lst->map[i][col] == 'N' || lst->map[i][col] == 'S'
				|| lst->map[i][col] == 'E' || lst->map[i][col] == 'W')
				count++;
			col++;
		}
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
			|| lst->map[line][col + 1] == 'E' || lst->map[line][col + 1] == 'W')
		&& (lst->map[line + 1][col] == '0' || lst->map[line + 1][col] == '1'
			|| lst->map[line + 1][col] == 'N' || lst->map[line + 1][col] == 'S'
			|| lst->map[line + 1][col] == 'E' || lst->map[line + 1][col] == 'W')
		&& (lst->map[line][col - 1] == '0' || lst->map[line][col - 1] == '1'
			|| lst->map[line][col - 1] == 'N' || lst->map[line][col - 1] == 'S'
			|| lst->map[line][col - 1] == 'E' || lst->map[line][col - 1] == 'W')
		&& (lst->map[line - 1][col] == '0' || lst->map[line - 1][col] == '1'
			|| lst->map[line - 1][col] == 'N' || lst->map[line - 1][col] == 'S'
			|| lst->map[line - 1][col] == 'E' || lst->map[line
			- 1][col] == 'W'))
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
			col++;
		}
	}
	return (false);
}
