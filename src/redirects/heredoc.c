/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:47:33 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 15:33:03 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	heredoc_loop(char *line, t_word *data, int fd[])
{
	while (1)
	{
		line = readline(">");
		if (!line || ft_strncmp(data->next->word, line, ft_strlen(line)
				+ 1) == 0)
			break ;
		else if (line)
		{
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
	}
	if (line)
		free(line);
	return (0);
}

int	heredoc(t_word *data)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		return (-1);
	line = NULL;
	heredoc_loop(line, data, fd);
	close(fd[1]);
	return (fd[0]);
}

int	append(t_word *data)
{
	t_word	*head;
	int		fd_out;

	head = data;
	while (head && head->flag != WORD)
		head = head->next;
	while (data && data->flag != PIPE)
	{
		if (data->flag == APPEND)
		{
			fd_out = open(data->next->word, O_WRONLY | O_CREAT | O_APPEND,
					0644);
			if (fd_out == -1)
			{
				perror("open");
				return (-1);
			}
			head->fd[1] = fd_out;
		}
		data = data->next;
	}
	return (0);
}
