/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:02:58 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 14:13:28 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_commands(t_word *word, t_env *env, char *full_path)
{
	if (word->word[0] == '/' || word->word[0] == '.')
	{
		if (execve(word->word, word->cmds, env_list_to_sstrs(env)) == -1)
		{
			printf("minishell: command not found %s\n", word->word);
			exit(127);
		}
	}
	else if (execve(full_path, word->cmds, env_list_to_sstrs(env)) == -1)
	{
		printf("minishell: command not found %s\n", word->word);
		exit(127);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

void	redir_stdout(t_word *word)
{
	if (word->fd[1] != STDOUT_FILENO)
	{
		dup2(word->fd[1], STDOUT_FILENO);
		close(word->fd[1]);
	}
	if (word->fd[0] != STDIN_FILENO)
	{
		dup2(word->fd[0], STDIN_FILENO);
		close(word->fd[0]);
	}
}

void	close_exec_fd(t_word *word)
{
	t_word	*current;

	current = word->head;
	while (current)
	{
		if (current->fd[1] != STDOUT_FILENO)
			close(current->fd[1]);
		if (current->fd[0] != STDIN_FILENO)
			close(current->fd[0]);
		current = current->next;
	}
}

char	*loop_path(char *cmd, t_word *word, char **args2)
{
	int		i;
	char	*ret;

	i = 0;
	while (args2[i])
	{
		cmd = ft_strjoin(args2[i], "/");
		ret = ft_strjoin(cmd, word->word);
		if (access(ret, F_OK) == 0)
			break ;
		i++;
	}
	return (ret);
}