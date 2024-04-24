/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:02:26 by felperei          #+#    #+#             */
/*   Updated: 2024/04/18 15:21:28 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(char **args)
{

	if ((execve(args[0], args, NULL)) == -2)
	{
		printf("Error execve\n");
		exit(1);
	}
}
void	redirect(char **av)
{
	int input_fd;
	int output_fd;
	int i;

	i = 0;
	input_fd = -1;
	output_fd = -1;

	while (av[i])
	{
		if (ft_strncmp(av[i], "<", ft_strlen(av[i])) == 0)
		{
			av[i] = NULL; // Terminar a lista de argumentos
			input_fd = open(av[i + 1], O_RDONLY);
			if (input_fd == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
		}
		else if (ft_strncmp(av[i], ">", ft_strlen(av[i])) == 0)
		{
			av[i] = NULL; // Terminar a lista de argumentos
			output_fd = open(av[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (output_fd == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	if (input_fd != -1)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (output_fd != -1)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}

	if (av[0] != NULL)
	{
		execute_command(av);
	}
}