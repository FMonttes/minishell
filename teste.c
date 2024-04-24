/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:20:57 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/19 16:20:33 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "minishell.h"

int main()
{
  while (42)
  {

    int fd[2];
    char *input = readline("minishell ");

    char **arg = split_adapted(input, '|');
    for (int i = 0; i < 3; i++)
        printf("%s\n",arg[i]);

    char **arg1 = ft_split(arg[0], ' ');

    char **arg2 = ft_split(arg[1], ' ');


  
    if (pipe(fd) == -1)
        perror("Pipe");
    pid_t pid1 = fork();

    if (pid1 == 0)
    {
    // child process 1 (ping)
        dup2(fd[1], STDOUT_FILENO);
        printf("oi\n");
        close(fd[0]);
        close(fd[1]);
        execve(arg[0], arg1, NULL);
    }
    else
     {
    /// father process 2
    
        waitpid(pid1, NULL, 0);
        printf("pai\n");
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve(arg[1], arg2, NULL);
    }
    close(fd[0]);
    close(fd[1]);
    free(input);
  }
  wait(NULL);
}*/