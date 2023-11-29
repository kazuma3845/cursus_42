/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:15:56 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/29 16:55:39 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c <= 90 && c >= 65) || (c <= 122 && c >= 97))
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long	ft_atoi(char *str)
{
	int		i;
	int		j;
	long	retourn;

	i = 0;
	j = 1;
	retourn = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) && str[i])
	{
		retourn *= 10;
		retourn += str[i] - '0';
		i++;
	}
	return (retourn * j);
}

int	ft_count(t_list **a, t_list *check)
{
	t_list	*current;
	int		count;

	count = 0;
	current = *a;
	while (current != NULL)
	{
		if (current->content < check->content)
			count++;
		current = current->next;
	}
	return (count);
}
