/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:09:10 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 14:36:36 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack_a
{
	void				*content;
	struct s_stack_a	*next;
}						t_stack_a;

typedef struct s_stack_b
{
	void				*content;
	struct s_stack_b	*next;
}						t_stack_b;

int						main(int argc, char **argv);
void					swap_a(t_stack_a a, t_stack_b b);
void					swap_b(t_stack_a a, t_stack_b b);
void					ss(t_stack_a a, t_stack_b b);
void					push_a(t_stack_a a, t_stack_b b);
void					push_b(t_stack_a a, t_stack_b b);
void					rotate_a(t_stack_a a, t_stack_b b);
void					rotate_b(t_stack_a a, t_stack_b b);
void					rr(t_stack_a a, t_stack_b b);
void					reverse_rotate_a(t_stack_a a, t_stack_b b);
void					reverse_rotate_b(t_stack_a a, t_stack_b b);
void					rrr(t_stack_a a, t_stack_b b);

#endif