/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neah <neah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:56:57 by frobain           #+#    #+#             */
/*   Updated: 2024/01/23 09:18:34 by neah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	skip_quotes(char const *s, int *i, char c)
{
	char	quote;

	quote = '\0';
	while (s[*i] && s[*i] != c)
	{
		if (s[*i] == '"' || s[*i] == '\'')
		{
			quote = s[*i];
			(*i)++;
			while (s[*i] != quote && s[*i])
				(*i)++;
		}
		(*i)++;
	}
}

int	ft_count_words_quotes(const char *s, char del)
{
	int		i;
	int		count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] == del && in_word)
			in_word = 0;
		else if (s[i] != del && !in_word)
		{
			in_word = 1;
			count++;
		}
		if (s[i] == '"' || s[i] == '\'')
			skip_quotes(s, &i, del);
		else
			i++;
	}
	return (count);
}

char	**ft_split_quotes(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count_words_quotes(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i] && j < ft_count_words_quotes(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		skip_quotes(s, &i, c);
		split[j] = ft_substr(s, start, i - start);
		if (!split[j])
			return (ft_free_split(split, j));
		j++;
	}
	split[j] = NULL;
	return (split);
}

// int	main(void)
// {
// 	char *str = "Voici une phrase avec des 'mots séparés par des espaces'";
// 	char **words;
// 	int i;

// 	words = ft_split_quotes(str, ' ');
// 	if (!words)
// 		return (1);

// 	i = 0;
// 	while (words[i])
// 	{
// 		printf("Mot %d: %s\n", i + 1, words[i]);
// 		free(words[i]);
// 		i++;
// 	}
// 	free(words);
// 	return (0);
// }