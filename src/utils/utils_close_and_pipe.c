/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_close_and_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:57:16 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 11:13:09 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	close_sentence_fd(t_word *word)
{
	while (word && word->flag != PIPE)
	{
		if (word->fd[0] != STDIN_FILENO)
			close(word->fd[0]);
		if (word->fd[1] != STDOUT_FILENO)
			close(word->fd[1]);
		word = word->next;
	}
}

int	ft_pipe(t_word *prompt)
{
	int		fd[2];
	t_word	*cmd;

	while (prompt)
	{
		cmd = prompt;
		while (prompt && prompt->flag != PIPE)
			prompt = prompt->next;
		if (!prompt)
			return (0);
		if (pipe(fd) == -1)
			return (1);
		cmd->fd[1] = fd[1];
		if (prompt->next)
			prompt->next->fd[0] = fd[0];
		else
			close_pipe(fd);
		prompt = prompt->next;
	}
	return (0);
}

t_word	*get_next_pipe(t_word *current)
{
	while (current)
	{
		if (current->flag == PIPE)
			return (current->next);
		current = current->next;
	}
	return (current);
}
