/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:46 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/24 11:25:01 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    pipe_exec(char *input, int fd[])
{
    char **cmds = ft_split(input, '|');
    char **args1 = ft_split(cmds[0], ' ');
    char **args2 = ft_split(cmds[1], ' ');
    char *cmd1 = ft_strjoin("/bin/", cmds[0]);
    char *cmd2 = ft_strjoin("/bin/", cmds[1]);
    printf("%s\n", cmd1);
    printf("%s\n", cmd2);
    if (pipe(fd) == -1)
        return ;

    int pid1 = fork();
    if (pid1 < 0)
        return ;
    if (pid1 == 0)
    {
        // child process 1 (ping)
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve(cmd1, args1, NULL);
    }

    else
    {
        /// child process 2 (grep)
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve(cmd2 , args2, NULL); 
        waitpid(pid1, NULL, 0);
    }
}