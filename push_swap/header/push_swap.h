/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:09:10 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:02:03 by tomuller         ###   ########.fr       */
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
	long			content;
	struct s_list	*next;
}					t_list;

int					main(int argc, char **argv);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_remove_nodes(t_list **a);
void				ft_remove_nodes_last(t_list **a);
void				ft_lstprint(t_list **head);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(long content);
void				swap_a(t_list **a, int i);
void				swap_b(t_list **b, int i);
void				ss(t_list **a, t_list **b);
void				push_a(t_list **a, t_list **b);
void				push_b(t_list **a, t_list **b);
void				rotate_a(t_list **a, int i);
void				rotate_b(t_list **b, int i);
void				rr(t_list **a, t_list **b);
void				reverse_rotate_a(t_list **a, int i);
void				reverse_rotate_b(t_list **b, int i);
void				rrr(t_list **a, t_list **b);
void				algo(t_list **a, t_list **b);
void				test(t_list **a, t_list **b);
char				**ft_split(char const *s, char c);
int					ft_isalnum(int c);
int					ft_strcmp(char *s1, char *s2);
long				ft_atoi(char *str);
void				free_liste(t_list **a);
void				if_is_3(t_list **a);
int					ft_count(t_list **a, t_list *check);
int					error(t_list **a);


#endif