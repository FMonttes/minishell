/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:56:03 by fmontes           #+#    #+#             */
/*   Updated: 2024/06/03 08:52:38 by fmontes          ###   ########.fr       */
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
	int pid;
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

size_t list_size(t_env *env);
size_t count_til_c(char *word, char c);
size_t get_env_var_name_size(char *string);

t_env *init_env(char **environ);

t_word *ft_lstnew(char *input);
t_word *create_word_lst(char *input);

int ft_isspace(int c);
int append(t_word *data);
int heredoc(t_word *data);
int do_redir(t_word *data);
int executor(t_word *word, t_env *env);

void cd(t_word *data);
void token(t_word *data);
void wait_cmds(t_word *node);
void print_list(t_word *head);
void print_list(t_word *head);
void echo_command(t_word *word);
void pwd(t_word *list, t_env *env);
void exec(t_word *word, t_env *env);
void print_env(char *input, t_env *env);
void bash_execs(t_word *list, t_env *env);
void env_command(char *input, t_env *env);
void redirect_env(char *input, t_env *env);
void unset_command(char *input, t_env *env);
void append_env_var(t_env *env, char *env_s);
void export_command(char *input, t_env *env);
void remove_quotes_all_prompt(t_word *prompt);
void apply_expand(t_word *prompt, t_env *env);
void ft_lstadd_back(t_word **lst, t_word *new);
void list_remove_if(t_env **env, char *str,
					int (*cmp)(const char *, const char *, size_t));
void handle_sigint(int signo);

int redirect(char **av);
int heredoc(t_word *data);
int ft_exit(t_word *data);
int count_quotes(char *input);
int hidenp(char *cmd, char *input);
int check_builtin(char *input, t_env *env);

char *strq(char *input);
char *first_word(char *input);
char **fill_list(t_word *data);
char *get_env_var_name(char *word);
char **env_list_to_sstrs(t_env *env);
char **env_list_to_sstrs(t_env *env);
char *expand_word(char *word, t_env *env);
char *join_expand(char *input, t_env *env);
char *get_env_var_value(t_env *env, char *var_name);
char *search_and_replace_customized(char *s, char old, char new);
char *remove_extra_spaces(char *str, int maintain_double_q_spaces);

#endif
