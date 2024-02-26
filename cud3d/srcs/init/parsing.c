/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:00:13 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/26 12:31:02 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_size(t_map *lst)
{
	int	i;
	int	j;
	int	max_x;

	i = -1;
	max_x = 0;
	while (lst->map[++i])
	{
		j = 0;
		while (lst->map[i][j])
			j += 1;
		if (j > max_x)
			max_x = j;
	}
	lst->map_height = i;
	lst->map_width = max_x;
}

void	change_map(t_map *lst)
{
	char	**tab;
	int		i;
	int		j;

	i = 6;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_arrlen(lst->map) - 5));
	while (lst->map[i] != NULL)
		tab[j++] = lst->map[i++];
	tab[j] = NULL;
	i = -1;
	while (++i != 6)
		free(lst->map[i]);
	free(lst->map);
	lst->map = tab;
	set_size(lst);
}

bool	map_error(t_map *lst)
{
	if (check_char(lst, -1))
		return (true);
	if (check_vide(lst))
		return (true);
	if (check_wall(lst))
		return (true);
	return (false);
}

bool	check_color(char *col)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_split(col, ',');
	while (++i < 3)
	{
		if (!split || !split[i])
		{
			free_tab(split);
			return (false);
		}
	}
	if (split[3])
	{
		free_tab(split);
		return (false);
	}
	free_tab(split);
	return (true);
}

bool	parsing(t_map *lst)
{
	if (!check_texture(lst))
	{
		printf("Error\nTexture not found\n");
		return (false);
	}
	init_texture(lst, 0);
	if (!texture_valide(lst))
	{
		printf("Error\nTexture path doesn't exists\n");
		return (false);
	}
	change_map(lst);
	if (map_error(lst))
	{
		printf("Error\nMap not valide\n");
		return (false);
	}
	if (!check_color(lst->c_tex) || !check_color(lst->f_tex))
	{
		printf("Error\nWrong color description\n");
		return (false);
	}
	return (true);
}
