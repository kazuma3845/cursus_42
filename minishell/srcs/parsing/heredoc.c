/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:29:38 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/12 13:51:34 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(char *key, char *s_start, char *s_end, char *to_add)
{
	if (key)
		free(key);
	if (s_start)
		free(s_start);
	if (s_end)
		free(s_end);
	if (to_add)
		free(to_add);
}

char	*replace_args(t_cmd *lst, int j, char *input)
{
	char	*key;
	char	*to_add;
	char	*s_start;
	char	*s_end;

	key = get_env_key(input, j);
	to_add = find_in_env(lst, key);
	s_start = ft_substr(input, 0, j);
	s_end = ft_substr(input, j + ft_strlen(key), ft_strlen(input) - (j
				+ ft_strlen(key)));
	free(input);
	free(key);
	if (s_start == NULL && s_end == NULL && to_add != NULL)
		input = to_add;
	else if (to_add == NULL)
		input = ft_strjoin(s_start, s_end);
	else
	{
		key = ft_strjoin(to_add, s_end);
		input = ft_strjoin(s_start, key);
	}
	free_all(key, s_start, s_end, to_add);
	return (input);
}

char	*expend(t_cmd *lst, char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '$' && (input[i] == '\'' || input[i] == '"'
				|| ft_isspace(input[i]) || input[i] == '\0'))
			input = replace_args(lst, i, input);
	}
	return (input);
}

void	heredoc_2(t_cmd *lst, char *pwd)
{
	char	*path;

	free(pwd);
	pwd = getcwd(NULL, 0);
	path = ft_strjoin(pwd, "/.temp");
	free(pwd);
	free(lst->dirin);
	lst->dirin = ft_strjoin("<", path);
	free(path);
}

void	ft_heredoc(t_cmd *lst, char *file, int *code_error)
{
	char	*input;
	int		oflag;
	int		num;
	char	*pwd;

	oflag = O_CREAT | O_TRUNC | O_WRONLY;
	num = open(file, oflag, 0644);
	if (num == -1)
		return ;
	pwd = ft_substr(lst->dirin, 2, ft_strlen(lst->dirin));
	while (1)
	{
		input = readline("> ");
		if (ft_strcmp(input, pwd) == 0)
			break ;
		input = expend(lst, input);
		ft_putendl_fd(input, num);
		free(input);
	}
	free(input);
	heredoc_2(lst, pwd);
	*code_error = 0;
}
