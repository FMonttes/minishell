/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:04:04 by felperei          #+#    #+#             */
/*   Updated: 2024/04/18 16:33:39 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_command_pipe(int i, char **args)
{
	if ((execve(args[i], args, NULL)) == -2)
	{
		printf("Error execve\n");
		exit(1);
	}
}
int	pipe_operator(int fd[], char **args)
{
	int	i;
	int	pid1;
	int	pid2;

	i = 0;
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	while (args[i])
	{
		if (ft_strncmp(args[i], "|", ft_strlen(args[i])) == 0)
		{
			if (pid1 == 0)
			{
                args[i] = NULL;
				printf("processo filho");
				// child process 1 (ping)
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				execute_command_pipe(0 ,args);
			}
			else
			{
				printf("processo pai");
				dup2(fd[0], STDIN_FILENO);
				close(fd[0]);
				close(fd[1]);
				execute_command_pipe(2, args);
				waitpid(pid1, NULL, 0);
			}
		}
		i++;
	}
}
// if (ft_strncmp(av[i], "<", ft_strlen(av[i])) == 0)
// 	{
// 		av[i] = NULL; // Terminar a lista de argumentos
// 		input_fd = open(av[i + 1], O_RDONLY);
// 		if (input_fd == -1)
// 		{
// 			perror("open");
// 			exit(EXIT_FAILURE);
// 		}
// 	}