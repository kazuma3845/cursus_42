/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:01:23 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/15 10:15:01 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_real(char *buffer, t_num *c)
{
	int		i;

	i = 0;
	while (buffer[i] == '0')
		i++;
	if (buffer[i] == '\0' && c->c != -1)
	{
		if (write(1, "0", 1) == -1)
			c->c = -1;
		else
			c->c += 1;
	}
	else
	{
		while (buffer[i] && c->c != -1)
		{
			if (write(1, &buffer[i++], 1) == -1)
				c->c += -1;
			else
				c->c += 1;
		}
	}
}

void	ft_putptr(void *replace, t_num *c)
{
	char			*hex_chars;
	char			buffer[16];
	unsigned char	nibble;
	ssize_t			len;
	ssize_t			i;

	hex_chars = "0123456789abcdef";
	len = sizeof(void *) * 2;
	i = len - 1;
	while (i >= 0)
	{
		nibble = (unsigned char)((size_t)replace & 15);
		buffer[i] = hex_chars[nibble];
		replace = (void *)((size_t)replace >> 4);
		i--;
	}
	buffer[len] = '\0';
	if (write(1, "0x", 2) == -1)
		c->c = -1;
	else
		c->c += 2;
	ft_real(buffer, c);
}

char	*ft_impr(char *str, int replace, void *string, t_num *c)
{
	while (*str != '%' && *str && c->c != -1)
	{
		if (write(1, str++, 1) == -1)
			c->c = -1;
		else
			c->c += 1;
	}
	if (*str == '%')
	{
		str++;
		if (*str == 'd' || *str == 'i')
			ft_putnbr(replace, c);
		if (*str == 'u')
			ft_putnbru(replace, c);
		if (*str == 'c')
			ft_putchar(replace, c);
		if (*str == 's')
			ft_putstr(string, c);
		if (*str == 'p')
			ft_putptr(string, c);
		if (*str == 'X' || *str == 'x')
			ft_puthex(replace, c, str);
		str++;
	}
	return (str);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		replace;
	char	*new;
	t_num	c;

	c.c = 0;
	replace = 0;
	va_start(arg, str);
	new = (char *)str;
	while (*new != '\0')
	{
		if (ft_finds(new) == 1)
			new = ft_impr(new, replace, va_arg(arg, char *), &c);
		else if (ft_findp(new) == 1)
			new = ft_impr(new, replace, va_arg(arg, void *), &c);
		else
			new = ft_impr(new, va_arg(arg, int), 0, &c);
		if (c.c == -1)
			break ;
	}
	va_end(arg);
	replace = c.c;
	return (replace);
}
