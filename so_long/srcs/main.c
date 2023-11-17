/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:41:37 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/17 14:20:29 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc != 2)
		return (write(1, "Error\nWrong number of arguments\n", 32));
	if (error_file(argv[1]) == 1)
		return (write(1, "Error\nFichier invalide\n", 23));
	map = ft_read(argv[1]);
	if (error_map(map) == 1)
		return (write(1, "Error\nMap false\n", 16));
	//	start_game(map);
	//	close_game(map);
	return (0);
}

char	**ft_read(char *file)
{
	char	**str;
	int		ligne;
	int		fd;

	ligne = 0;
	fd = open(file, O_RDONLY);
	str = (char **)malloc(sizeof(char *) * 11);/////////////////////////////////////////////////////////////////////
	while ((str[ligne] = get_next_line(fd)) != NULL)
		ligne++;
	close(fd);
	return (str);
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
