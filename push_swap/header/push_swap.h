/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:09:10 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 19:20:16 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*previous;
	void			*content;
	struct s_list	*next;
}					t_list;

int					main(int argc, char **argv);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void *content);
void					swap_a(t_list **a);
void					swap_b(t_list **b);
void					ss(t_list **a, t_list **b);
void					push_a(t_list **a, t_list **b);
void					push_b(t_list **a, t_list **b);
// void					rotate_a(t_list *a, t_list *b);
// void					rotate_b(t_list *a, t_list *b);
// void					rr(t_list *a, t_list *b);
// void					reverse_rotate_a(t_list *a, t_list *b);
// void					reverse_rotate_b(t_list *a, t_list *b);
// void					rrr(t_list *a, t_list *b);

#endif