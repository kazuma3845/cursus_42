/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:41:24 by tomuller          #+#    #+#             */
/*   Updated: 2023/10/27 15:49:56 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa2(char *str, int long n, int long i)
{
	int long	j;

	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n > 9)
	{
		j = n % 10;
		ft_itoa2(str, n / 10, i - 1);
		n = j;
	}
	str[i] = n + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int long	i;
	int long	j;

	i = 0;
	j = n;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	if (n < 0)
		i++;
	if (n == 0)
		i = 1;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	str = ft_itoa2(str, n, i - 1);
	str[i] = '\0';
	return (str);
}
