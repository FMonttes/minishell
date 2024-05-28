/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_execs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:14:45 by felperei          #+#    #+#             */
/*   Updated: 2024/05/28 09:47:47 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **fill_list(t_word *data)
{
	int i;
	int z;
	char **ret;
	t_word *current;

	current = data;
	z = 0;
	i = 0;
	while (current && current->flag == WORD)
	{
		i++;
		current = current->next;
	}
	ret = malloc(sizeof(char *) * i + 1);
	current = data;
	while (z < i)
	{
		ret[z] = ft_strdup(current->word);
		z++;
		current = current->next;
	}
	ret[z] = NULL;
	return (ret);
}

void exec(t_word *word, t_env *env)
{
	int i;
	int ok;
	char *path;
	char *full_path;
	char **args2;
	char *cmd;
	t_word *current;
	// extern unsigned int exit_status;

	if (word->fd[1] != STDOUT_FILENO)
		dup2(word->fd[1], STDOUT_FILENO);
	if (word->fd[0] != STDIN_FILENO)
		dup2(word->fd[0], STDIN_FILENO);
	current = word->head;
	while (current)
	{
		if (word->fd[1] != STDOUT_FILENO)
			close(word->fd[1]);
		else if (word->fd[0] != STDIN_FILENO)
			close(word->fd[0]);
		current = current->next;
	}

	word->cmds = fill_list(word);
	args2 = ft_split(getenv("PATH"), ':');
	i = 0;
	while (args2[i])
	{
		cmd = ft_strjoin(args2[i], "/");
		full_path = ft_strjoin(cmd, word->word);
		if (access(full_path, F_OK) == 0)
		{
			ok = access(full_path, F_OK);
			break;
		}
		i++;
	}

	if (execve(full_path, word->cmds, env_list_to_sstrs(env)) == -1)
	{
		printf("minishell: command not found %s\n", full_path);
		// exit_status = 127;
		exit(127);
	}
	else
		exit(EXIT_SUCCESS);
}

void bash_execs(t_word *data, t_env *env)
{
	__pid_t pid;
	// extern unsigned int exit_status;

	pid = fork();
	if (pid == 0)
		exec(data, env);
	waitpid(pid, NULL, 0);
	// exit_status = WEXITSTATUS(status);
}

t_word *get_next_pipe(t_word *current)
{
	while (current)
	{
		if (current->flag == PIPE)
			return (current->next);
		current = current->next;
	}
	return (current);
}

void exec_pipe(t_word *word, t_env *env)
{
	word->pid = fork();
	if (word->pid != 0)
		return;
	exec(word, env);
}

void ft_pipe(t_word *word)
{
	int fd[2];
	t_word *cmd;

	while (word)
	{
		while (word && word->flag != PIPE && word->flag != WORD)
			word = word->next;
		cmd = word;
		while (word && word->flag != PIPE)
			word = word->next;
		if (!word)
			return;
		if (pipe(fd) == -1)
			return;
		cmd->fd[1] = fd[1];
		word = word->next;
		cmd = word;
		while (cmd && cmd->flag != PIPE && cmd->flag != WORD)
			cmd = cmd->next;
		if (cmd)
			word->fd[0] = fd[0];
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
}

void close_sentence_fd(t_word *word)
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

void executor(t_word *word, t_env *env)
{
	int has_pipe;
	t_word *current;

	current = word;
	ft_pipe(word);
	has_pipe = 0;
	while (current)
	{
		if (current->flag == PIPE)
		{
			has_pipe = 1;
			break;
		}
		current = current->next;
	}
	current = word;
	while (current)
	{
		if (count_quotes(word->raw_cmd) % 2 == 0)
		{
			if (has_pipe)
				exec_pipe(current, env);
			else
			{
				printf("bash_execs()\n");
				bash_execs(current, env);
			}
		}
		close_sentence_fd(current);
		current = get_next_pipe(current);
	}
}
