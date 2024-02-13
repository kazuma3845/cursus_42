/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:00:31 by neah              #+#    #+#             */
/*   Updated: 2024/02/12 10:47:22 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(int error_code, int *code_error)
{
	if (error_code == 3)
		printf("Syntax error : missing closing quotes.\n");
	if (error_code == 4)
		printf("Redirection failure : check file name.\n");
	if (error_code == 5)
		printf("Syntax error : redirection file might be missing.\n");
	if (error_code == 6)
		printf("Syntax error : no command found.\n");
	if (error_code == 8)
		printf("Fork failure.\n");
	if (error_code == 9)
		printf("Error : too many arguments provided.\n");
	if (error_code == 10)
		printf("Error : directory not found.\n");
	if (error_code == 11)
		printf("Error : invalid arguments.\n");
	if (error_code == 7)
		printf("Pipe failure.\n");
	if (error_code == 127)
		printf("Execution failure : command path not found\n");
	*code_error = error_code;
	return (error_code);
}
