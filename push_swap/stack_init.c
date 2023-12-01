/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:06:57 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:06:58 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	i;
	long	nbr;
	int		minus;

	i = 0;
	nbr = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		minus *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (int) str[i] - 48;
		i++;
	}
	nbr *= minus;
	return (nbr);
}

static void	add_node(t_stack **stack, int number)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->number = number;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = stk_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	init_stack_a(t_stack **a, char **argv)
{
	int	i;
	long	number;

	i = 0;
	while (argv[i])
	{
		if (error_int(argv[i]) == 1)
			error(a);
		number = ft_atol(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
			error(a);
		if (error_dup(a, number) == 1)
			error(a);
		add_node(a, number);
		i++;
	}
}
