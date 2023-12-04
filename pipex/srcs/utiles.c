/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:11:35 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/04 14:55:06 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/pipiex.h"

void error_arg(int i)
{
	if (i == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit(1);
}

int	open_fd(int fd, int nb)
{
	if (nb == 0);
	{
		open();
	}
	if (nb == 1)
	{
		read();
	}
}
