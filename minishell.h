/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:56:03 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/28 09:29:12 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#define DOUBLE_QUOTES 34
#define SINGLE_QUOTE 39

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/libftprintf.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

typedef enum s_tokens
{
	PIPE,
	HDOC,
	APPEND,
	RDIN,
	RDOUT,
	EMPTY,
	WORD
} t_tkn;

typedef struct s_word
{
	int fd[2];
	int flag;
	int i;
	int status;
	char *word;
	char **cmds;
	char *raw_cmd;
	struct s_word *head;
	struct s_word *next;
	t_tkn *token;
	__pid_t pid;
} t_word;

typedef struct l_stack
{
	int size;
	t_word *head;
} t_stack;

typedef struct s_env
{
	char *env_var_s;
	char **environ;
	struct s_env *next;
} t_env;

t_env *init_env(char **environ);

t_word *ft_lstnew(char *input);
t_word *creat_list(char *input);

size_t list_size(t_env *env);

void executor(t_word *word, t_env *env);

void cd(t_word *data);
void echo(char *input);
void init_signals(void);
void token(t_word *data);
void print_pwd(char *input);
void print_echo(char *input);
void sigint_handler(int sig);
void print_list(t_word *head);
void sigquit_handler(int sig);
void print_list(t_word *head);
void pwd(t_word *list, t_env *env);
void exec(t_word *word, t_env *env);
void unset(char *input, t_env *env);
void pipe_exec(char *input, int fd[]);
void print_env(char *input, t_env *env);
void creat_env(char *input, t_env *env);
void bash_execs(t_word *list, t_env *env);
void env_command(char *input, t_env *env);
void echo_command(char *input, t_env *env);
void redirect_env(char *input, t_env *env);
void unset_command(char *input, t_env *env);
void append_env_var(t_env *env, char *env_s);
void export_command(char *input, t_env *env);
void list_remove_if(t_env **env, char *str,
					int (*cmp)(const char *, const char *, size_t));

int redirect(char **av);
int ft_exit(t_word *data);
int count_quotes(char *input);
int heredoc(char **args, t_env *env);
int print_exit_status(char *input);
int hidenp(char *cmd, char *input);
int pipe_operator(int fd[], char **args);
int check_builtin(char *input, t_env *env);
int print_builtin(char *input, char **env);

char *first_word(char *input);
char *remove_e_spaces(char *input);
char **env_list_to_sstrs(t_env *env);
char *strq(char *input);
char *join_expand(char *input, t_env *env);
char *remove_extra_spaces(char *str, int maintain_double_q_spaces);

char **get_path(void);
char **env_list_to_sstrs(t_env *env);
char **get_params(char *input, char **params, char **words, char *command);

#endif
