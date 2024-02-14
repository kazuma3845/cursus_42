/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neah <neah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:38:10 by neah              #+#    #+#             */
/*   Updated: 2023/12/04 19:06:30 by neah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long n)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (neg == 1)
		return (i + 1);
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;

	nbr = n;
	len = ft_intlen(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_itoa(-2147483648);
// 	printf("–2147483648 -> %s\n", result);
// 	free(result); // Remember to free memory
// 	result = ft_itoa(-12345);
// 	printf("-12345 -> %s\n", result);
// 	free(result); // Remember to free memory
// 	result = ft_itoa(0);
// 	printf("0 -> %s\n", result);
// 	free(result); // Remember to free memory
// 	return (0);
// }
