/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:34:56 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/08 16:27:19 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct c_struct
{
	char	*str;
}	t_struct;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strduplicate(const char *s1, int size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*fill_line_buffer(int fd, char *left_c, char *buffer);
char	*ft_line_str(char *wait);
char	*ft_line_left(char *wait);

#endif