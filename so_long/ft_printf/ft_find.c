/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:11:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/15 10:18:23 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_finds(const char *ltr)
{
	while (*ltr != '%' && *ltr)
		ltr++;
	if (*ltr == '\0')
        return (0);
	ltr++;
	if (*ltr == 's')
		return (1);
	return (0);
}

int	ft_findp(const char *ltr)
{
	while (*ltr != '%' && *ltr)
		ltr++;
	if (*ltr == '\0')
        return (0);
	ltr++;
	if (*ltr == 'p')
		return (1);
	return (0);
}

void	ft_putnbru(long int n, t_num *c)
{
	if (n < 0)
	{
		n = -n;
		n = 4294967296 - n;
		ft_putnbru(n, c);
	}
	else if (n > 9)
	{
		ft_putnbru((n / 10), c);
		ft_putnbru((n % 10), c);
	}
	else
	{
		ft_putchar((n + 48), c);
	}
}
