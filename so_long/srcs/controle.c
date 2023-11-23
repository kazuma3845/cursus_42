/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:47:21 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 11:47:45 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	item_png(t_game *map)
{
	int	i;
	int	j;

	if (map->map[map->y][map->x + 1] == 'E')
		map->map[map->y][map->x + 1] = 'I';
	if (map->map[map->y][map->x - 1] == 'E')
		map->map[map->y][map->x - 1] = 'I';
	if (map->map[map->y + 1][map->x] == 'E')
		map->map[map->y + 1][map->x] = 'I';
	if (map->map[map->y - 1][map->x] == 'E')
		map->map[map->y - 1][map->x] = 'I';
	map->exit = mlx_xpm_file_to_image(map->mlxpointer, "texture/o_exit.xpm", &i,
			&j);
}

void	fonc_exit(t_game *map)
{
	int	line;

	line = 0;
	if (map->winpointer)
		mlx_destroy_window(map->mlxpointer, map->winpointer);
	free(map->mlxpointer);
	while (line < map->y_max)
		free(map->map[line++]);
	free(map->map);
	exit(0);
}

int	controle(int commande, t_game *map)
{
	static int	nbr;

	if (commande == 53)
		fonc_exit(map);
	if (commande == 13)
		up(map, 13);
	if (commande == 1)
		down(map, 1);
	if (commande == 0)
		left(map, 0);
	if (commande == 2)
		right(map, 2);
	if (commande == 13 || commande == 1 || commande == 0 || commande == 2)
	{
		nbr++;
		ft_printf("Mouvement: %i\n", nbr);
	}
	add_image_window(map, nbr);
	if (map->nbr_item == 0)
		item_png(map);
	return (1);
}

char	*ft_itoa2(char *str, int long n, int long i)
{
	int long	j;

	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n > 9)
	{
		j = n % 10;
		ft_itoa2(str, n / 10, i - 1);
		n = j;
	}
	str[i] = n + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int long	i;
	int long	j;

	i = 0;
	j = n;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	if (n < 0)
		i++;
	if (n == 0)
		i = 1;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	str = ft_itoa2(str, n, i - 1);
	str[i] = '\0';
	return (str);
}
