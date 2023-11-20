/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:41:37 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/20 17:10:50 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	info;

	if (argc != 2)
		return (write(1, "Error\nWrong number of arguments\n", 32));
	if (error_file(argv[1]) == 1)
		return (write(1, "Error\nFichier invalide\n", 23));
	ft_read(argv[1], &info);
	//  if (error_map(&info) == 1)
	// 	return (write(1, "Error\nMap false\n", 16));
	// start_game(info);
	return (0);
}

static int	temp(int ligne, t_game *map, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (ligne + 1));
	tmp[ligne] = NULL;
	while (i < ligne - 1)
	{
		tmp[i] = map->map[i];
		i++;
	}
	tmp[i] = line;
	if (map->map)
		free(map->map);
	map->map = tmp;
	return (1);
}

void	ft_read(char *file, t_game *map)
{
	char	*line;
	int		ligne;
	int		fd;

	ligne = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		ligne++;
		temp(ligne, map, line);
	}
	map->ligne = ligne;
	ligne = 0;
	while (map->map[0][ligne] != '\n')
		ligne++;
	map->col = ligne;
	close(fd);
}

int	error_file(char *file)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	str = ".ber";
	i = 4;
	while (file[j])
		j++;
	while (i != 0)
	{
		if (file[j] != str[i])
			return (1);
		i--;
		j--;
	}
	return (0);
}
