/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:02:26 by felperei          #+#    #+#             */
/*   Updated: 2024/05/31 11:41:21 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int loop_redir_in(t_word *data, t_word *head, int fd_in)
{
	t_word *current;
	current = data;

	while (current && current->flag != PIPE)
	{
		if (current->flag == RDIN)
		{
			if (access(current->next->word, F_OK | X_OK) != 1)
			{
				
				fd_in = open(current->next->word, O_RDONLY);
				if (fd_in == (-1))
				{
					perror("open");
					return (-1);
				}
				head->fd[0] = fd_in;
			}
		else
			{
				printf("Error: No such file as '%s'\n", current->next->word);
				return (-1);
			}
		}
		else if (current->flag == HDOC)
			head->fd[0] = heredoc(current);
		current = current->next;
	}
}

int redir_out(t_word *data)
{
	t_word *current;
	current = data;
	int fd_out;
	while (current && current->flag != WORD)
		current = current->next;
	while (current && current->flag != PIPE)
	{
		if (current->flag == RDOUT)
		{
				fd_out = open(current->next->word, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (fd_out == -1)
				{
					perror("open");
					return (-1);
				}
				current->fd[1] = fd_out;
			dup2(current->fd[1], STDIN_FILENO);
		}
		current = current->next;
	}

	return (0);
}
int	redir_in(t_word *data)
{
	t_word	*head;
	int		fd_in;
		dup2(data->fd[1], STDOUT_FILENO);
	fd_in = -1;
	head = data;
	while (head && head->flag != WORD)
		head = head->next;
	if (loop_redir_in(data, head, fd_in) == -1)
		return (-1);

		// dup2(fd_in, STDIN_FILENO);

	return (0);
}

int	do_redir(t_word *data)
{
	if (!data)
		return (0);
	if (redir_in(data)
		|| redir_out(data)
		|| append(data))
		return (-1);
	return (0);
}
