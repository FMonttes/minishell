/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_execs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <felipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:28:51 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 18:44:36 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec(t_word *word, t_env *env)
{
	char	**args2;
	char	*cmd;
	t_env	*current;
	char	*full_path;

	cmd = ft_strdup("");
	current = env;
	while (current)
	{
		if (ft_strncmp("PATH", current->env_var_s, 4) == 0)
			break ;
		current = current->next;
	}
	redir_stdout(word);
	close_exec_fd(word);
	word->cmds = fill_list(word);
	args2 = ft_split(current->env_var_s, ':');
	full_path = loop_path(cmd, word, args2);
	exec_commands(word, env, full_path);
	free_args(args2);
}

void	bash_execs(t_word *data, t_env *env)
{
	__pid_t				pid;
	extern unsigned int	g_exit_status;

	pid = fork();
	if (pid == 0)
	{
		exec(data, env);
	}
	else if (pid > 0)
	{
		waitpid(pid, &data->status, 0);
		if (WIFEXITED(data->status))
		{
			g_exit_status = WEXITSTATUS(data->status);
		}
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

void	exec_pipe(t_word *word, t_env *env)
{
	word->pid = fork();
	if (word->pid == 0)
	{
		exec(word, env);
	}
}

int	loop_executor(t_word *current, int has_pipe, t_env *env)
{
	while (current)
	{
		if (do_redir(current))
			return (1);
		if (has_pipe)
			exec_pipe(current, env);
		else if (is_builtin(current, env) != 0)
			bash_execs(current, env);
		close_sentence_fd(current);
		current = get_next_pipe(current);
	}
	return (0);
}

int	executor(t_word *word, t_env *env)
{
	int		has_pipe;
	t_word	*current;

	current = word;
	ft_pipe(word);
	has_pipe = 0;
	while (current)
	{
		if (current->flag == PIPE)
		{
			has_pipe = 1;
			break ;
		}
		current = current->next;
	}
	current = word;
	loop_executor(current, has_pipe, env);
	return (0);
}
