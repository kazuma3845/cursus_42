/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:59:12 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/21 10:47:37 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

void	clean_all(t_map *lst)
{
	free_tab(lst->map);
	free(lst->n_tex);
	free(lst->s_tex);
	free(lst->e_tex);
	free(lst->w_tex);
	free(lst->f_tex);
	free(lst->c_tex);
}
