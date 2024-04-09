/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:56:03 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/09 17:00:38 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "../libft42/libft.h"
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>


//builtins
void    echo(char *input);
void    print_env(char *input, char **env);
int     count_quotes(char *input);
char    *strq(char *input, char *comand);
void    pwd(char *input);
void    cd(char *input);
int   ft_exit(char *input);
void    creat_env(char *input, char **env);
void    unset(char *input, char **env);

#endif