/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:10:09 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:10:10 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy != NULL)
	{
		while (s1[i] != '\0')
		{
			copy[i] = s1[i];
			++i;
		}
		copy[i] = '\0';
	}
	return (copy);
}
