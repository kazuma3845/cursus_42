/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:07:31 by neah              #+#    #+#             */
/*   Updated: 2024/02/08 15:11:28 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*new_arg_and_free(char *to_add, char *s_start, char *s_end)
{
	char	*middle;
	char	*new_arg;

	if (s_start == NULL && s_end == NULL && to_add != NULL)
	{
		new_arg = to_add;
		free(to_add);
	}
	else if (to_add == NULL)
	{
		new_arg = ft_strjoin(s_start, s_end);
		free(s_start);
		free(s_end);
	}
	else
	{
		middle = ft_strjoin(to_add, s_end);
		new_arg = ft_strjoin(s_start, middle);
		free(middle);
		free(s_start);
		free(s_end);
		free(to_add);
	}
	return (new_arg);
}

/*
 * replace_args - Remplace les variables d'environnement dans un argument
 * @lst: pointeur vers la structure t_cmd
 * @i: index de l'argument à modifier
 * Ne retourne rien

	* Remplace les variables d'environnement dans l'argument à l'index 'i'
	par leurs valeurs.
 */

void	replace_arg(t_cmd *lst, int i, int j, int *code_error)
{
	char	*key;
	char	*to_add;
	char	*s_start;
	char	*s_end;

	if (ft_strcmp(lst->args[i], "$?") == 0)
	{
		free(lst->args[i]);
		lst->args[i] = ft_itoa(*code_error);
		return ;
	}
	key = get_env_key(lst->args[i], j);
	if (!key)
		return ;
	to_add = find_in_env(lst, key);
	s_start = ft_substr(lst->args[i], 0, j);
	s_end = ft_substr(lst->args[i], j + ft_strlen(key), ft_strlen(lst->args[i])
			- (j + ft_strlen(key)));
	free(lst->args[i]);
	if (key)
		free(key);
	lst->args[i] = new_arg_and_free(to_add, s_start, s_end);
}

char	*delete_double_quotes(t_cmd *lst, int i)
{
	int		j;
	int		y;
	char	quotes;
	char	*copy;

	quotes = '\0';
	j = -1;
	y = 0;
	copy = malloc(ft_strlen(lst->args[i]) + 1);
	if (!copy)
		return (NULL);
	ft_bzero(copy, ft_strlen(lst->args[i]) + 1);
	while (lst->args[i][++j])
	{
		while (lst->args[i][j] == '\'' || lst->args[i][j] == '"')
		{
			quotes = lst->args[i][j++];
			while (lst->args[i][j] != quotes && lst->args[i][j])
				copy[y++] = lst->args[i][j++];
			j++;
		}
		copy[y++] = lst->args[i][j];
	}
	return (copy);
}

/**
 * expand_args - Étend les variables d'environnement et supprime les guillemets
 * @lst: pointeur vers la structure t_cmd
 * Ne retourne rien
 * Parcourt tous les arguments,
	étend les variables d'environnement et supprime les guillemets.
 */

void	expand_args(t_cmd *lst, int *code_error)
{
	int		i;
	int		j;
	char	quotes;
	char	*tmp;

	quotes = '\0';
	i = -1;
	while (lst->args[++i])
	{
		j = -1;
		while (lst->args[i][++j])
		{
			in_quotes(lst->args[i][j], &quotes);
			if (lst->args[i][j] == '$' && quotes != '\'' && (lst->args[i][j
				+ 1] == '\'' || lst->args[i][j + 1] == '"'
				|| ft_isspace(lst->args[i][j + 1]) || lst->args[i][j
				+ 1] == '\0'))
				j++;
			else if (lst->args[i][j] == '$' && quotes != '\'')
				replace_arg(lst, i, j, code_error);
		}
		tmp = delete_double_quotes(lst, i);
		free(lst->args[i]);
		lst->args[i] = tmp;
	}
}
