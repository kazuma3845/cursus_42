/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:35:22 by frobain           #+#    #+#             */
/*   Updated: 2024/02/13 13:05:20 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// line 24 = Print the current directory
// line 26 = Print SHLVL in red
void	minishell_loop(char ***venv, int *code_error, int shlvl)
{
	char	*input;
	char	*prompt;

	while (1)
	{
		signal_setup(1);
		prompt = getcwd(NULL, 0);
		printf(B "%s " RST "[" R "\033[31m%d\033[0m" RST "]\n", prompt, shlvl);
		input = readline(G " 🐢 > " RST);
		if (!input)
		{
			free(prompt);
			break ;
		}
		if (*input)
		{
			signal_setup(2);
			add_history(input);
			parsing(input, venv, code_error);
		}
		unlink(".temp");
		free(input);
		free(prompt);
	}
	clear_history();
}

int	main(int argc, char **argv, char **env)
{
	char	**venv;
	int		code_error;
	int		shlvl;

	code_error = 0;
	if (argc > 1)
	{
		printf("Error : Minishell doesn't take any arguments.\n");
		return (ft_error(13, &code_error));
	}
	(void)argv;
	venv = dup_env(env, &shlvl);
	minishell_loop(&venv, &code_error, shlvl);
	free_tab(venv);
	return (0);
}
