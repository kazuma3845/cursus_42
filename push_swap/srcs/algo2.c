/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:51:38 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/29 16:51:14 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	if_is_3_case_2(t_list **a)
{
	rotate_a(a, 0);
	if ((*a)->content > (*a)->next->content)
		swap_a(a, 0);
}

void	if_is_3_case_0(t_list **a)
{
	t_list	*check;

	check = (*a)->next;
	if (check->next == NULL)
		return ;
	if (check->content > check->next->content)
	{
		rotate_a(a, 0);
		swap_a(a, 0);
		reverse_rotate_a(a, 0);
	}
}

void	if_is_3(t_list **a)
{
	int	count;

	count = ft_count(a, *a);
	if (count == 2)
		if_is_3_case_2(a);
	else if (count == 1)
	{
		if ((*a)->content > (*a)->next->content)
			swap_a(a, 0);
		else
			reverse_rotate_a(a, 0);
	}
	else if (count == 0)
		if_is_3_case_0(a);
}

int	error(t_list **a)
{
	t_list	*check;
	t_list	*current;

	check = (*a)->next;
	current = *a;
	while (current)
	{
		if (current->content < -2147483648 || current->content > 2147483647)
			return (1);
		while (check)
		{
			if (current->content == check->content)
				return (1);
			check = check->next;
		}
		current = current->next;
		if (current != NULL)
			check = current->next;
	}
	return (0);
}
