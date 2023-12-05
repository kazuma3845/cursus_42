/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:11:35 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/05 13:48:28 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	error_arg(int i)
{
	if (i == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit(1);
}

int	open_fd(char *fd, int nb)
{
	int	file;

	if (nb == 0)
		file = open(fd, O_RDONLY, 0777);
	if (nb == 1)
		file = open(fd, O_WRONLY, O_EXCL, O_CREAT, 0777);
	if (file == -1)
		exit(0);
	return (file);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

char	*my_getenv(char *str, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strncmp(sub, str, ft_strlen(sub)) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (0);
}

char	*get_path(char *cmd, char **env)
{
	char	*i_dont_now;
	char	*never_gonna_give_you_up;
	char	**know_i_now;
	char	**envie_de_crever;
	int		aled;

	aled = -1;
	envie_de_crever = ft_split(my_getenv("PATH", env), ':');
	know_i_now = ft_split(cmd, ' ');
	while (envie_de_crever[++aled])
	{
		i_dont_now = ft_strjoin(envie_de_crever[aled], "/");
		never_gonna_give_you_up = ft_strjoin(i_dont_now, know_i_now[0]);
		free(i_dont_now);
		if (access(never_gonna_give_you_up, F_OK | X_OK) == 0)
		{
			free_tab(know_i_now);
			return (never_gonna_give_you_up);
		}
		free(never_gonna_give_you_up);
	}
	free_tab(envie_de_crever);
	free_tab(know_i_now);
	return (cmd);
}
