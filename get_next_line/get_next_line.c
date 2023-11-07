/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:34:53 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/07 11:16:14 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buffer;
	char		*str;

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buffer)
		return (0);
	str = fill_line_buffer(fd, left, buffer);
	free(buffer);
	left = set_line(str);
	return (str);
}

char	*fill_line_buffer(int fd, char *left, char *buffer)
{
	char	*str;
	ssize_t	i;

	i = read(fd, buffer, BUFFER_SIZE);
	if (i == -1)
	{
		free(left);
		return (NULL);
	}
	if (i == 0)
		return (0);
	str = ft_strjoin(left, buffer);
	return (str);
}

char	*set_line(char *line_buffer)
{
	static char	*left;
	char		*str;
	int			i;

	i = 0;
	while (line_buffer[i] != '\n' || line_buffer[i])
		i++;
	str = malloc(sizeof(char *) * i + 1);
	if (str)
		return (0);
	ft_strlcpy(str, line_buffer, i);
	left = ft_strdup(line_buffer + i);
	return (left);
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
