/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:56:03 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/29 15:40:51 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "libft42/libft.h"
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>

//builtins
void    bash_execs(char *input, char **env);
char	**split_adapted(char  *s, char c);
void    echo(char *input);
void    print_env(char *input, char **env);
char    *first_word(char *input);
int     count_quotes(char *input);
char    *strq(char *input, char *comand);
void    pwd(char *input);
void    cd(char *input);
int   ft_exit(char *input);
void    creat_env(char *input, char **env);
void    unset(char *input, char **env);
char *remove_extra_spaces(char *input); 
int    check_builtin(char *input, char **env);
int hidenp(char *cmd, char *input);
void	redirect(char **av);
char **get_path(void);
char **get_params(char *input, char **params, char **words, char *command);
int	pipe_operator(int fd[], char **args);
void    pipe_exec(char *input, int fd[]);
char *remove_spaces(char *input);
void    ft_pipe(char *input, char **env, int *fd);
void	ft_heredoc(char *input);

#endif