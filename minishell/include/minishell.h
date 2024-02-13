/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:57:44 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/12 16:10:07 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RST "\033[0m"
# define R "\033[1;31m"
# define B "\033[1;34m"
# define G "\033[1;32m"

typedef struct s_cmd	t_cmd;

typedef int				(*t_builtin)(t_cmd *cmd_lst);

typedef struct s_cmd
{
	char				*path;
	char				*cmd;
	char				**args;
	t_builtin			builtin;
	char				*dirin;
	char				*dirout;
	t_cmd				*next;
	char				**env;
}						t_cmd;

typedef struct s_builtin_map
{
	char				*name;
	t_builtin			func;
}						t_builtin_map;

typedef struct s_pid_list
{
	int					pid;
	struct s_pid_list	*next;
}						t_pid_list;

typedef struct s_exec_pipeline_context
{
	int					in_fd;
	int					out_fd;
	t_pid_list			*pid_list;
	int					saved_stdout;
	int					saved_stdin;
}						t_exec_pipeline_context;

// MAIN
int						main(int argc, char **argv, char **env);
void					minishell_loop(char ***venv, int *code_error,
							int shlvl);
// BUILT
int						built_cd(t_cmd *lst);
int						real_cd(t_cmd *lst, char *env, char *oldpwd);
int						cd_2(t_cmd *lst, char *pwd, char *oldpwd);

int						built_echo(t_cmd *lst);

int						built_env(t_cmd *lst);

int						built_exit(t_cmd *lst);

int						built_export(t_cmd *lst);
int						check_maj_args(char **arg);
int						ft_ismaj(char *c);

int						built_pwd(t_cmd *lst);

int						built_unset(t_cmd *lst);
char					**delet_env(t_cmd *lst, char *args, char **tab,
							int *code_error);
char					*find_in_env(t_cmd *lst, char *to_find);

int						ft_find_equal(char *env);
// ENV
void					change_env(t_cmd *lst, char *pwd, char *key);
int						is_env(t_cmd *lst, char *modif);
void					add_env(t_cmd *lst, char *pwd);

char					*get_env_key(char *s, int j);
int						find_env_index(t_cmd *lst, char *args);
// EXEC
int						redirect(int oldfd, int newfd, int *code_error);
void					add_pid(t_pid_list **pid_list, int pid);
void					free_pid_list(t_pid_list *pid_list);
void					wait_pids(t_pid_list *pid_list, int *code_error);
void					handle_next_cmd(t_cmd *cmd, int *fd, int *in_fd,
							int *out_fd);

void					exec_pipeline(t_cmd *cmd, int *code_error);
void					run_cmds(t_cmd *cmd_lst, int *code_error);

int						configure_input_redirection(t_cmd *cmd, int *in_fd);
int						configure_output_redirection(t_cmd *cmd, int *out_fd);
int						configure_redirections(t_cmd *cmd, int *in_fd,
							int *out_fd);
void					initialize_exec_pipeline(t_exec_pipeline_context *ctx);
void					cleanup_exec_pipeline(t_exec_pipeline_context *ctx,
							int *code_error);
// EXPAND
void					expand_args(t_cmd *lst, int *code_error);
char					*delete_double_quotes(t_cmd *lst, int i);
void					replace_arg(t_cmd *lst, int i, int j, int *code_error);
char					*new_arg_and_free(char *to_add, char *s_start,
							char *s_end);
// PARSING
bool					check_dir(t_cmd *lst);
bool					check_quotes(t_cmd *lst);
int						ft_strreach(char *str, char *cmp);
int						is_builtin(t_cmd *lst);
bool					is_programm(t_cmd *lst);

void					ft_heredoc(t_cmd *lst, char *file, int *code_error);
void					heredoc_2(t_cmd *lst, char *pwd);
char					*expend(t_cmd *lst, char *input);
char					*replace_args(t_cmd *lst, int j, char *input);
void					free_all(char *key, char *s_start, char *s_end,
							char *to_add);

int						parsing(const char *input, char ***env,
							int *code_error);
bool					check_cmds(t_cmd *lst);
bool					check_curr_node_quotes(t_cmd *lst);
t_cmd					*init_cmd(char **split, char ***env);
void					add_redirection(char **cmd_split, int *j, t_cmd *node);

void					check_path(t_cmd *list);
char					**dup_env(char **env, int *shlvl);
char					*get_path(t_cmd *list);
int						check_env(t_cmd *lst, char *env, char ***path,
							char ***commande);
// UTILS
void					free_cmd_list(t_cmd *cmd_lst);
void					free_tab(char **tab);
void					leaks(char **commande, char **path, char *env, int i);
void					free_check_cmd(char **split, t_cmd *cmd_lst);

int						ft_error(int error_code, int *code_error);

void					cmd_lstadd_back(t_cmd **lst, t_cmd *new);
t_cmd					*cmd_lastlst(t_cmd *lst);
t_cmd					*create_new_cmd_node(char **cmd_split, char ***env);
void					add_args(char *arg, t_cmd *node, int *i);
void					update_cmd_with_builtin(t_cmd *node);

void					handler(int signal);
void					handler2(int signal);
void					signal_setup(int handler_num);

void					init_map(t_builtin_map *builtin_map);
bool					in_quotes(char c, char *curr_quotes);
t_cmd					*init_node_variables(t_cmd *node);

#endif