/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:06:50 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:06:51 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//      Commands
void	push(t_stack **a, t_stack **b, char *str);
void	swap(t_stack **a, char *str);
void	rotate(t_stack **head, char *str);
void	reverse_rotate(t_stack **head, char *str);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);

//      Push_swap_utils
t_stack	*stk_max(t_stack *stk);
t_stack	*stk_min(t_stack *stk);
bool	stk_sorted(t_stack *stack);
int		stk_size(t_stack *stk);
t_stack	*stk_last(t_stack *lst);
t_stack	*stk_find(t_stack *stk, t_stack *stk_to_find);
void	free_after_split(char **tab);
void	print_stk(t_stack *lst);

//      Init_a
void	current_index(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);

//      Stack_init
void	init_stack_a(t_stack **a, char **argv);
t_stack	*find_cheapest(t_stack *stack);

//      Init_b
void	init_nodes_b(t_stack *a, t_stack *b);

//      Algo
void	multi_algo(t_stack **a, t_stack **b);
void	duo_algo(t_stack **a);
void	trio_algo(t_stack **a);
void	find_algo(t_stack **a, t_stack **b);

//      Move
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	set_order(t_stack **a);

//      Error
void	error(t_stack **a);
int		error_int(char *s);
int		error_dup(t_stack **a, int number);
void	free_stack(t_stack **a);

#endif
