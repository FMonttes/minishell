/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:02:26 by felperei          #+#    #+#             */
/*   Updated: 2024/05/24 08:54:06 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_av(char **av, int input_fd, int output_fd)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_strncmp(av[i], "<", ft_strlen(av[i])) == 0)
		{
			av[i] = NULL;
			input_fd = open(av[i + 1], O_RDONLY);
			if (input_fd == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
		}
		else if (ft_strncmp(av[i], ">", ft_strlen(av[i])) == 0)
		{
			av[i] = NULL;
			output_fd = open(av[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (output_fd == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

int	redirect(char **av)
{
	int input_fd;
	int output_fd;

	input_fd = -1;
	output_fd = -1;
	loop_av(av, input_fd, output_fd);
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
	return (0);
}
