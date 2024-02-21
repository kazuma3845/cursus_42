/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:56:39 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/21 10:48:00 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && (line[i] < 8 || line[i] > 13))
			return (true);
	}
	return (false);
}

void	copy_tab(t_map *lst, char *line, int ligne)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (ligne + 1));
	tmp[ligne] = NULL;
	while (i < ligne - 1)
	{
		tmp[i] = lst->map[i];
		i++;
	}
	if (lst->map)
		free(lst->map);
	tmp[i] = strdup(line);
	lst->map = tmp;
}

void	init_texture(t_map *lst, int i)
{
	char	**var;

	if (i > 6)
		return ;
	var = ft_split(lst->map[i], ' ');
	if (ft_strcmp(var[0], "NO") == 0)
		lst->n_tex = ft_strdup(var[1]);
	if (ft_strcmp(var[0], "SO") == 0)
		lst->s_tex = ft_strdup(var[1]);
	if (ft_strcmp(var[0], "WE") == 0)
		lst->w_tex = ft_strdup(var[1]);
	if (ft_strcmp(var[0], "EA") == 0)
		lst->e_tex = ft_strdup(var[1]);
	if (ft_strcmp(var[0], "F") == 0)
		lst->f_tex = ft_strdup(var[1]);
	if (ft_strcmp(var[0], "C") == 0)
		lst->c_tex = ft_strdup(var[1]);
	free_tab(var);
	init_texture(lst, i + 1);
}

void	init_tab(t_map *lst, char *argv)
{
	char	*line;
	int		ligne;
	int		fd;

	ligne = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (check_line(line) || ligne > 6)
		{
			ligne++;
			copy_tab(lst, line, ligne);
		}
		free(line);
	}
	close(fd);
}

bool	check_arg(char *argv)
{
	if (ft_strnstr(argv, ".cub", ft_strlen(argv)))
		return (true);
	printf("Error\nWrong file extension\n");
	return (false);
}
