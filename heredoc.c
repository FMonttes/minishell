/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:42:32 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/14 11:25:32 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	execute_command(char **args)
{

	if ((execve(args[0], args, NULL)) == -2)
	{
		printf("Error execve\n");
		exit(1);

	}
}*/
int	heredoc(char **args)
{
	int output_fd;
	int fd[2];
	int i;
	char *delimitador;
	char *input;
	i = 0;
	output_fd = -1;
	pipe(fd);
	while (args[i])
	{
		if (ft_strncmp(args[i], "<<", ft_strlen(args[i])) == 0)
		{
			args[i] = NULL;
			 delimitador =  args[i + 1];
				while (1)
				{
					input = readline(">");
					if (ft_strncmp(input, delimitador, ft_strlen(delimitador)) == 0)
					{
						free(input);
						break;
					}
				}
		}
		else if (ft_strncmp(args[i], ">>", ft_strlen(args[i])) == 0)
		{
			args[i] = NULL;
			output_fd = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (output_fd == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	if (output_fd != -1)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
}