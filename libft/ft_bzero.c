/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:16:47 by tomuller          #+#    #+#             */
/*   Updated: 2023/10/25 11:48:12 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = s;
	if (n != 0)
	{
		while (i != n)
		{
			a[i] = 0;
			i++;
		}
	}
}
