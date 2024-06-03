#include "minishell.h"

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
		printf("minishell: command not found %s\n", word->word);
		// exit_status = 127;
		exit(127);
	}
	else
		exit(EXIT_SUCCESS);
}

void bash_execs(t_word *data, t_env *env)
{
	__pid_t pid;
	extern unsigned int g_exit_status;

	pid = fork();
	if (pid == 0)
		exec(data, env);
	waitpid(pid, &(data->status), 0);
	if (WIFEXITED(data->status))
		g_exit_status = WEXITSTATUS(data->status);
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

void close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	return;
}

int ft_pipe(t_word *prompt)
{
	int fd[2];
	t_word *cmd;

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
		prompt = prompt->next;
		cmd = prompt;
		if (cmd)
			cmd->fd[0] = fd[0];
		else
			close_pipe(fd);
	}
	return (0);
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

int executor(t_word *word, t_env *env)
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
		if (has_pipe)
			exec_pipe(current, env);
		else
			bash_execs(current, env);
		close_sentence_fd(current);
		current = get_next_pipe(current);
	}
	return (0);
}
