/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:34:53 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/08 16:18:07 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buffer;
	char		*str;
	char		*wait;

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (BUFFER_SIZE < 0 || read(fd, 0, 0) < 0 || fd < 0)
	{
		free(left);
		free(buffer);
		left = NULL;
		buffer = NULL;
		return (NULL);
	}
	wait = fill_line_buffer(fd, left, buffer);
	free(buffer);
	if (wait == NULL)
		return (NULL);
	left = ft_line_left(wait);
	str = ft_line_str(wait);
	free(wait);
	return (str);
}

char	*fill_line_buffer(int fd, char *left, char *buffer)
{
	ssize_t	rnum;

	rnum = 1;
	while (rnum > 0)
	{
		rnum = read(fd, buffer, BUFFER_SIZE);
		if (rnum == -1)
		{
			free(left);
			return (NULL);
		}
		else if (rnum == 0)
			break ;
		if (left == NULL)
			left = ft_strdup(buffer);
		else
			left = ft_strjoin(left, buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (left);
}

char	*ft_line_left(char *wait)
{
	char	*left;
	int		i;

	i = 0;
	while (wait[i] != '\n' && wait[i])
		i++;
	if (wait[i] == '\n')
		i++;
	left = ft_strdup(wait + i);
	return (left);
}

char	*ft_line_str(char *wait)
{
	char	*str;
	int		i;

	i = 0;
	while (wait[i] != '\n' && wait[i])
		i++;
	if (wait[i] == '\n')
		i++;
	str = ft_strduplicate(wait, i);
	return (str);
}
