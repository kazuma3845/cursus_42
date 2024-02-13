/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:54:51 by frobain           #+#    #+#             */
/*   Updated: 2023/11/29 14:21:17 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_fd(t_list **lst, int fd)
{
	t_list	*temp;
	t_list	*before;

	temp = *lst;
	before = NULL;
	while (temp)
	{
		if (temp->fd == fd)
		{
			if (before)
				before->next = temp->next;
			else
				*lst = temp->next;
			free(temp->content);
			free(temp);
			return ;
		}
		before = temp;
		temp = temp->next;
	}
}

t_list	*ft_lstnew_fd(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->content = ft_strdup("");
	new->next = NULL;
	return (new);
}

t_list	*get_fd_list(t_list **lst, int fd)
{
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew_fd(fd);
	temp->next = *lst;
	*lst = temp;
	return (temp);
}

char	*extract_line(t_list **lst)
{
	char	*line;
	char	*temp;
	int		len;

	len = 0;
	while ((*lst)->content[len] && (*lst)->content[len] != '\n')
		len++;
	if ((*lst)->content[len] == '\n')
		len++;
	line = ft_substr((*lst)->content, 0, len);
	temp = ft_strdup((*lst)->content + len);
	free((*lst)->content);
	(*lst)->content = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*current;
	char			buffer[BUFFER_SIZE + 1];
	int				rd;
	char			*temp_line;

	current = get_fd_list(&lst, fd);
	rd = read(fd, buffer, BUFFER_SIZE);
	while (rd > 0)
	{
		buffer[rd] = '\0';
		temp_line = ft_strjoin(current->content, buffer);
		free(current->content);
		current->content = temp_line;
		if (ft_strchr(buffer, '\n'))
			break ;
		rd = read(fd, buffer, BUFFER_SIZE);
	}
	if (rd == -1 || (rd == 0 && current->content[0] == '\0'))
	{
		ft_lstclear_fd(&lst, fd);
		return (NULL);
	}
	return (extract_line(&current));
}
