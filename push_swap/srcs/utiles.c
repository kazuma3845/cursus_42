/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:44:40 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/29 10:45:58 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (dstsize != 0)
	{
		while (i != dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = ft_strlen(s);
	j = 0;
	if (s == NULL)
		return (0);
	if (i < start)
	{
		len = 0;
		start = 0;
	}
	if (i > start)
		j = i - start;
	if (j > len)
		j = len;
		str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s + start, j + 1);
	return (str);
}

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
