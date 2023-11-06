/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:34:53 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/06 16:33:15 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left;
	t_struct	tab;
	char		*buffer;
	char		*str;

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	str = fill_line_buffer(fd, left, buffer);
	free(buffer);
	left = set_line(str);
	return (tab.str);
}

char	*fill_line_buffer(int fd, char *left, char *buffer)
{
	char		*str;
	ssize_t		i;

	i = read(fd, buffer, BUFFER_SIZE);
	if (i == -1)
	{
		free(left);
		return (NULL);
	}
	str = ft_strjoin(left, buffer);
	return (str);
}

char	*set_line(char *line_buffer)
{
	static char	*str;
	char		*hades;
	int			i;

	i = 0;
	while (line_buffer[i] != '\n' || line_buffer[i])
		i++;
	str = ft_strdup(line_buffer + i);
	return (str);
}

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
