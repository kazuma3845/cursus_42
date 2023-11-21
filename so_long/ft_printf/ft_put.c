/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:10:10 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/21 15:43:08 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_putchar(char c, t_num *r)
{
	if (r->c != -1)
	{
		if (write(1, &c, 1) == -1)
			r->c = -1;
		else
			r->c += 1;
	}
}

void	ft_putstr(char *c, t_num *r)
{
	int	i;

	i = 0;
	if (c == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			r->c = -1;
		else
			r->c += 6;
	}
	else
	{
		while (c[i] && r->c != -1)
		{
			if (write(1, &c[i++], 1) == -1)
				r->c = -1;
			else
				r->c += 1;
		}
	}
}

void	ft_putnbr(int n, t_num *c)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", c);
	}
	else if (n < 0)
	{
		ft_putchar('-', c);
		n = -n;
		ft_putnbr(n, c);
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10), c);
		ft_putnbr((n % 10), c);
	}
	else
	{
		ft_putchar((n + 48), c);
	}
}

void	ft_puthex(long int string, t_num *c, char *str)
{
	int		i;

	if (c->c == -1)
		return ;
	if (string < 0)
		string = 4294967296 + string;
	i = string;
	if (string > 15)
	{
		ft_puthex(string / 16, c, str);
		ft_puthex(string % 16, c, str);
	}
	else
		ft_puthex2(i, c, str);
}

void	ft_puthex2(long int i, t_num *c, char *str)
{
	char	*hex;
	char	*maj;

	hex = "0123456789abcdef";
	maj = "0123456789ABCDEF";
	if (*str == 'x' && c->c != -1)
	{
		if (write(1, &hex[i], 1) == -1)
			c->c = -1;
		else
			c->c += 1;
	}
	else if (*str == 'X' && c->c != -1)
	{
		if (write(1, &maj[i], 1) == -1)
			c->c = -1;
		else
			c->c += 1;
	}
}
