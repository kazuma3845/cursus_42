/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:59:12 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/19 16:36:53 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

void	clean_all(t_map *lst)
{
	if (lst->map)
		free_tab(lst->map);
	if (lst->n_texture != NULL)
		free(lst->n_texture);
	if (lst->s_texture != NULL)
		free(lst->s_texture);
	if (lst->e_texture != NULL)
		free(lst->e_texture);
	if (lst->w_texture != NULL)
		free(lst->w_texture);
	if (lst->f_texture != NULL)
		free(lst->f_texture);
	if (lst->c_texture != NULL)
		free(lst->c_texture);
}
