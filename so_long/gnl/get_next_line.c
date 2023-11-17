/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:34:53 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/17 14:06:06 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	*get_next_line(int fd)
{
	static char	*left;
	char		*str;

	if (BUFFER_SIZE < 0 || read(fd, 0, 0) < 0 || fd < 0)
	{
		free(left);
		left = NULL;
		return (NULL);
	}
	str = fill_line_buffer(fd, left);
	if (str == NULL)
		return (NULL);
	left = line_left(str);
	str = line_str(str);
	return (str);
}

char	*fill_line_buffer(int fd, char *left)
{
	ssize_t	rnum;
	char	*buffer;

	rnum = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (rnum > 0 && !ft_strchr(left, '\n'))
	{
		rnum = read(fd, buffer, BUFFER_SIZE);
		if (rnum == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (rnum == 0)
			break ;
		buffer[rnum] = '\0';
		left = ft_strjoin(left, buffer);
	}
	free(buffer);
	return (left);
}

char	*line_left(char *str)
{
	char	*left;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == 0)
		return (NULL);
	left = ft_strdup(&str[i]);
	return (left);
}

char	*line_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	str[i] = '\0';
	return (str);
}
