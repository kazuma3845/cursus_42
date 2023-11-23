/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:46:14 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:46:57 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static size_t	nbr(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s != c && *s)
				++s;
		}
		else
			++s;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (nbr(s, c) + 1));
	if (str == NULL)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s != '\0' && *s != c && ++len)
				++s;
			str[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	str[i] = 0;
	return (str);
}
