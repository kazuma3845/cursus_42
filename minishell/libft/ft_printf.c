/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:20:55 by frobain           #+#    #+#             */
/*   Updated: 2023/11/29 14:26:06 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

int	ft_check_next(const char *data, int i, va_list args, int *count)
{
	if (data[i + 1] == 'c')
		ft_putchar(va_arg(args, int), count);
	if (data[i + 1] == 's')
		ft_putstr(va_arg(args, char *), count);
	if (data[i + 1] == 'p')
	{
		write(1, "0x", 2);
		ft_puthex_ptr(va_arg(args, unsigned long), 'x', count);
		(*count) += 2;
	}
	if (data[i + 1] == 'i' || (data[i + 1] == 'd'))
		ft_putnbr(va_arg(args, int), count);
	if (data[i + 1] == 'u')
		ft_uns_putnbr(va_arg(args, unsigned int), count);
	if ((data[i + 1] == 'X') || (data[i + 1] == 'x'))
		ft_puthex(va_arg(args, int), (char)data[i + 1], count);
	if (data[i + 1] == '%')
		ft_putchar('%', count);
	return (0);
}

int	ft_printf(const char *data, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, data);
	while (data[i])
	{
		if (data[i] == '%')
		{
			ft_check_next(data, i, args, &count);
			i += 2;
		}
		else
		{
			ft_putchar(data[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}
// int	main(void)
// {
// 	int x = 10;
//     void *ptr = &x;

// 	ft_printf("My printf: %s \n", "Hello");
// 	printf("Printf original : %s", "Hello");
// }
