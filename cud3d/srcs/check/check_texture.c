/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:47:11 by nreichel          #+#    #+#             */
/*   Updated: 2024/02/21 10:50:30 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	all_found(bool *check)
{
	int	i;

	i = 0;
	while (check[i] == true)
		i += 1;
	return (i == 6);
}

bool	check_exist(bool *check, char *str)
{
	if (ft_strcmp(str, "NO") == 0)
		check[0] = true;
	else if (ft_strcmp(str, "SO") == 0)
		check[1] = true;
	else if (ft_strcmp(str, "WE") == 0)
		check[2] = true;
	else if (ft_strcmp(str, "EA") == 0)
		check[3] = true;
	else if (ft_strcmp(str, "F") == 0)
		check[4] = true;
	else if (ft_strcmp(str, "C") == 0)
		check[5] = true;
	else
		return (false);
	return (true);
}

bool	check_texture(t_map *lst)
{
	int		i;
	char	**str;
	bool	check[6];

	i = -1;
	while (++i < 6)
		check[i] = false;
	i = -1;
	while (lst->map[++i] && i < 6)
	{
		str = ft_split(lst->map[i], ' ');
		if (!check_exist(check, str[0]))
		{
			free_tab(str);
			return (false);
		}
		free_tab(str);
	}
	return (all_found(check));
}
