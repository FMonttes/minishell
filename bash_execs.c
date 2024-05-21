/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_execs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:58:27 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/21 15:25:55 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t list_size(t_env *env)
{
	size_t counter;
	t_env *current;

	counter = 0;
	current = env;
	while (current)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}

char **env_list_to_sstrs(t_env *env)
{
	int i;
	char **sstrs;
	t_env *current;

	sstrs = malloc(sizeof(char *) * list_size(env) + 1);
	current = env;
	i = 0;
	while (current)
	{
		sstrs[i] = current->env_var_s;
		current = current->next;
		i++;
	}
	sstrs[i] = NULL;
	return (sstrs);
}

void exec(char *input, char **args, t_env *env)
{
	// extern unsigned int exit_status;
	int i;
	char *path;
	char **args2;
	int ok;
	char *full_path;
	char *cmd;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '.' || args[i][0] == '/')
			execve(args[i], args, env_list_to_sstrs(env));
		i++;
	}
	args2 = ft_split(getenv("PATH"), ':');
	i = 0;
	while (args2[i])
	{
		cmd = ft_strjoin(args2[i], "/");
		full_path = ft_strjoin(cmd, first_word(input));

		if (access(full_path, F_OK) == 0)
		{
			ok = access(full_path, F_OK);
			break;
		}
		i++;
	}
	if (execve(full_path, args, env->environ) == -1)
	{
		printf("minishell: command not found %s\n", full_path);
		// exit_status = 127;
		exit(127);
	}
	else
		exit(EXIT_SUCCESS);
}

void bash_execs(char *input, char **args, t_env *env, int *fd)
{
	char *path;
	__pid_t pid;
	int x = 0;
	int status;
	// extern unsigned int exit_status;

	if (!*input)
		return;
	pid = fork();
	if (pid == 0)
	{
		redirect(args);
		if (heredoc(input, env, fd))
			exit(1);
		exec(input, args, env);
	}
	waitpid(pid, &status, 0);
	// exit_status = WEXITSTATUS(status);
}