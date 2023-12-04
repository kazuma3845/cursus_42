/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipiex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:51:36 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/04 14:27:14 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void error_arg(int i);
int	open_fd(int fd, int nb);

#endif