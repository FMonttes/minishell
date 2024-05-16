/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:33:30 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/16 13:20:50 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *strq(char *input, char *comand)
{
    int i;
    int x;
    char *cmd;

    i = 0;
    x = 0;
    cmd = malloc(ft_strlen(input) + 1);
    while (input[i])
    {
        if (input[i] == 39 || input[i] == 34)
            i++;
        else
            cmd[x++] = input[i++];
    }
    cmd[x] = '\0';
    if (ft_strncmp(cmd, comand, ft_strlen("env")) == 0)
        return (cmd);
    // return ("syntax error");
}

void print_env(char *input, t_env *env)
{
    int i;
    int x;
    char *cmd;
    t_env *current = env;
    x = 0;
    cmd = strq(input, "env");
    if (count_quotes(input) % 2 == 0)
    {
        if (strncmp(cmd, "env", ft_strlen(cmd)) == 0)
        {
            while (current)
            {
                ft_printf("%s\n", current->env_var_s);
                current = current->next;
            }
        }
    }
    else
        ft_printf("invalid syntax\n");
}

void redirect_env(char *input, t_env *env)
{
    int i;
    int fd;
    char *output_fd;
    char **args;

    args = ft_split(input, ' ');

    if (ft_strncmp(args[0], "env", ft_strlen(args[0])) == 0)
    {
        i = 0;
        while (args[i])
        {
            if (ft_strncmp(args[i], ">", ft_strlen(args[i])) == 0)
            {
                args[i] = NULL;
                fd = open(args[i + 1], O_WRONLY, O_CREAT, O_APPEND, 0666);
            }
            i++;
        }
        t_env *current = env;
        while (current)
        {
            write(fd, ft_strjoin(current->env_var_s, "\n"),
                  ft_strlen(ft_strjoin(current->env_var_s, "\n")));
            current = current->next;
        }
        close(fd);
    }
}

void env_command(char *input, t_env *env)
{
    char **args;

    args = ft_split(input, ' ');
    if (ft_strncmp(args[0], "env", ft_strlen(args[0])) == 0)
    {
        print_env(input, env);
    }
}