/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:15:43 by frobain           #+#    #+#             */
/*   Updated: 2023/11/29 14:20:56 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int nbr, char letter, int *count)
{
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, letter, count);
	}
	if (nbr % 16 < 10)
		ft_putchar(nbr % 16 + '0', count);
	else if (letter == 'X')
		ft_putchar(nbr % 16 - 10 + 'A', count);
	else
		ft_putchar(nbr % 16 - 10 + 'a', count);
}
