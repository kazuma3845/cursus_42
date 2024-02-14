/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:19:40 by frobain           #+#    #+#             */
/*   Updated: 2023/11/29 14:21:25 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_uns_putnbr(unsigned int nb, int *count)
{
	if (nb >= 10)
	{
		ft_uns_putnbr(nb / 10, count);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + '0', count);
}
