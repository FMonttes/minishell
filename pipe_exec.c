/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:46 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/24 15:12:34 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    pipe_exec(char *input, int fd[])
{
    char **cmds = ft_split(input, '|');
    char **args = ft_split(input, ' ');
    /*char *cmd1 = ft_strjoin("/bin/", first_word(cmds[0]));
    char *cmd2 = ft_strjoin("/bin/", first_word(cmds[1]));*/
    if (pipe(fd) == -1)
        return ;
    int i = 1;
    int pid1 = fork();
    if (pid1 < 0)
        return ;
    while (args[i - 1])
	{
        // char **args1 = ft_split(cmds[i - 1], ' ');
        // char **args2 = ft_split(cmds[i], ' ');
	    if (ft_strncmp(args[i], "|", ft_strlen(args[i])) == 0)
	    {  

            if (pid1 == 0)
            {
                close(fd[0]);
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
                execve(ft_strjoin("/bin/", first_word(cmds[i - 1])), ft_split(cmds[i - 1], ' '), NULL);
            }
            else
            {
                close(fd[1]);
                dup2(fd[0], STDIN_FILENO);
                close(fd[0]);
                execve(ft_strjoin("/bin/", first_word(cmds[i])) , ft_split(cmds[i], ' '), NULL);
                waitpid(pid1, NULL, 0);
            }
        }
        i++;           
    }
}