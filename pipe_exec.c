/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:25:51 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/29 15:38:40 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void save_output(int current_fd, char **commands, int *fd, char **env)
{
    dup2(current_fd, STDIN_FILENO);
    if (*(commands + 1) != NULL)
        dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    if (check_builtin(*commands, env))
        exit(1);
    else if (execve(ft_strjoin("/bin/", first_word(*commands)),
            ft_split(*commands, ' '), NULL) == -1)
    {
        printf("minishell: command not found: %s\n", first_word(*commands));
        exit(EXIT_FAILURE);
    }
}

static void    exec_outputs(char **env, char **commands, int *fd, __pid_t pid)
{
    int        current_fd;

    current_fd = 0;
    while (*commands != NULL)
    {
        pipe(fd);
        pid = fork();
        if (pid == 0)
            save_output(current_fd, commands, fd, env);
        wait(NULL);
        close(fd[1]);
        current_fd = fd[0];
        commands++;
    }
}

void    ft_pipe(char *input, char **env, int *fd)
{
    char    **commands;
    __pid_t    pid;

    commands = ft_split(input, '|');
    exec_outputs(env, commands, fd, pid);
}
