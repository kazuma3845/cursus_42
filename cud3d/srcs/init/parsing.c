/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:00:13 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/20 14:26:37 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool	parsing(t_map *lst)
{
	if (!check_texture(lst))
	{
		printf("Error\nTexture not found\n");
		return (false);
	}
	init_texture(lst, 0);
	change_map(lst);
	if (map_error(lst))
	{
		printf("Error\nMap not valide\n");
		return (false);
	}
	return (true);
}
