/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:58:44 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/18 11:30:23 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
	 return (0);
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

bool check_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && (line[i] < 9 || line[i] > 13))
			return (true);
	}
	return (false);
}

void copy_tab(t_map *lst, char *line, char **tab)
{
   int i;

    i = -1;
    while (lst->map[++i])
        tab[i] = ft_strdup(lst->map[i]);
    tab[i] = ft_strdup(line);
    tab[++i] = NULL;
	lst->map = tab;
}

void init_texture(t_map *lst)
{
	char **var;

	var = ft_split(lst->map[0], ' ');
	lst->n_texture = var[1];
	var = ft_split(lst->map[1], ' ');
	lst->s_texture = var[1];
	var = ft_split(lst->map[2], ' ');
	lst->w_texture = var[1];
	var = ft_split(lst->map[3], ' ');
	lst->e_texture = var[1];
}

void init_tab(t_map *lst, char *argv)
{
	char *line;
	char **tab;
	int fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (check_line(line))
		{
			tab = malloc(sizeof(char *) * (ft_arrlen(lst->map) + 2));
			printf("");
			copy_tab(lst, line, tab);	
		}
	}
	init_texture(lst);
}

bool parsing()
{
	return (true);
}

int main(int argc, char **argv)
{
	t_map map;
	int i = -1;

	if (argc == 2)
	{
	init_tab(&map, argv[1]);
	// if (parsing())
		printf("------------SUCCES------------\n\nnorth : %s\nsouth : %s\neast : %s\nwest : %s\n\n\n", map.n_texture, map.s_texture, map.e_texture, map.w_texture);
	while (map.map[++i])
		printf("%s", map.map[i]);
	// free_tab(map);
	}
	return 0;
}
