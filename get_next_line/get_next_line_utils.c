/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:34:49 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/08 17:16:13 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc(sizeof (char) * (i + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (*s1 != '\0')
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	tab = (char *)malloc(sizeof (char) * (i + 1));
	if (tab == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strduplicate(const char *s1, int size)
{
	char	*tab;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (i > size)
		i = size;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (0);
	i = 0;
	while (s1[i] && i != size)
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while ((char)c != *s)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}
