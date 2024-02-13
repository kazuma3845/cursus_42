/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:05:50 by neah              #+#    #+#             */
/*   Updated: 2024/02/08 09:55:43 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * find_in_env - Recherche une variable dans l'environnement
 * @lst: pointeur vers la structure t_cmd
 * @to_find: chaîne à rechercher
 * Retourne un pointeur vers la valeur de la variable d'environnement,
	ou NULL si non trouvée
 * Parcourt l'environnement à la recherche d'une correspondance avec 'to_find'.
 */

char	*find_in_env(t_cmd *lst, char *to_find)
{
	int		i;
	char	*current_env;
	char	*env_key;

	if (to_find == NULL)
		return (NULL);
	to_find += 1;
	i = 0;
	while (lst->env[i])
	{
		current_env = lst->env[i];
		env_key = ft_substr(current_env, 0, ft_strlen(current_env)
				- ft_strlen(ft_strchr(current_env, '=')));
		if (env_key && ft_strncmp(env_key, to_find, ft_strlen(to_find)) == 0
			&& ft_strncmp(env_key, to_find, ft_strlen(env_key)) == 0)
		{
			free(env_key);
			return (ft_strdup(ft_strchr(current_env, '=') + 1));
		}
		free(env_key);
		i++;
	}
	return (NULL);
}
/**
 * get_env_key - Extrait la clé de l'environnement d'une chaîne
 * @s: la chaîne contenant la clé
 * @j: position de départ pour l'extraction
 * Retourne la clé extraite
 * Extrait la clé en sautant les espaces,
	et en s'arrêtant aux guillemets ou à l'espace.
 */

char	*get_env_key(char *s, int j)
{
	int	start;

	start = j;
	j++;
	if (s[j] == '$')
		return (NULL);
	while (ft_isspace(s[j]) != 1 && s[j] != '\'' && s[j] != '"' && s[j]
		&& s[j] != '$')
		j++;
	return (ft_substr(s, start, j - start));
}
