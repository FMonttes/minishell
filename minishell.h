/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:56:03 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/23 12:31:30 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#define DOUBLE_QUOTES 34
#define SINGLE_QUOTE 39

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
    char *word;
    char **cmds;
    struct s_word *head;
    struct s_word *next;
    t_tkn *token;
} t_word;

typedef struct l_stack
{
    t_word *head;
    int size;
} t_stack;

typedef struct s_env
{
    char *env_var_s;
    char **environ;
    struct s_env *next;
} t_env;

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include "libft/libft.h"
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

t_word *creat_list(char *input);
t_word *ft_lstnew(char *input);
void print_list(t_word *head);
void bash_execs(t_word *list, t_env *env);
int heredoc(char *cmd, t_env *env);
void init_signals(void);
int print_exit_status(char *input);
char **env_list_to_sstrs(t_env *env);
void exec(t_word *data, t_env *env);
void sigint_handler(int sig);
void sigquit_handler(int sig);
char *join_expand(char *input, t_env *env);
void echo(char *input);
void print_env(char *input, t_env *env);
char *first_word(char *input);
int count_quotes(char *input);
char *strq(char *input, char *comand);
void pwd(char *input, t_env *env);
void cd(char *input);
int ft_exit(char *input);
void creat_env(char *input, t_env *env);
void unset(char *input, t_env *env);
char *remove_e_spaces(char *input);
int check_builtin(char *input, t_env *env);
int hidenp(char *cmd, char *input);
int redirect(char **av);
char **get_path(void);
char **get_params(char *input, char **params, char **words, char *command);
int pipe_operator(int fd[], char **args);
void pipe_exec(char *input, int fd[]);
char *remove_spaces(char *input);
void print_echo(char *input);
void ft_pipe(t_word *word, t_env *env);
void print_pwd(char *input);
char *remove_extra_spaces(char *str, int maintain_double_q_spaces);
void echo_command(char *input, t_env *env);
t_env *init_env(char **environ);
void append_env_var(t_env *env, char *env_s);
void redirect_env(char *input, t_env *env);
void env_command(char *input, t_env *env);
int print_builtin(char *input, char **env);
void list_remove_if(t_env **env, char *str,
                    int (*cmp)(const char *, const char *, size_t));
void unset_command(char *input, t_env *env);
void export_command(char *input, t_env *env);

#endif
