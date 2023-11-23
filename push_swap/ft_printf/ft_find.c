/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:11:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:50:31 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_finds(const char *ltr)
{
	while (*ltr != '%' && *ltr)
		ltr++;
	ltr++;
	if (*ltr == 's')
		return (1);
	return (0);
}

int	ft_findp(const char *ltr)
{
	while (*ltr != '%' && *ltr)
		ltr++;
	ltr++;
	if (*ltr == 'p')
		return (1);
	return (0);
}

int	ft_findpourcent(const char *ltr)
{
	while (*ltr != '%' && *ltr)
		ltr++;
	ltr++;
	if (*ltr == '%')
		return (1);
	return (0);
}

char	*ft_putpourcent(char *str, t_num *c)
{
	while (*str != '%' && *str && c->c != -1)
	{
		if (write(1, str++, 1) == -1)
			c->c = -1;
		else
			c->c += 1;
	}
	if (*str == '%' && c->c != -1)
	{
		str++;
		if (write(1, "%", 1) == -1)
			c->c = -1;
		else
			c->c += 1;
		str++;
	}
	return (str);
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
