/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_execs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:58:27 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/20 13:59:57 by fmontes          ###   ########.fr       */
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
	int i;
	char *path;
	char **args2;
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
		if ((execve(ft_strjoin(cmd, first_word(input)),
					args, env->environ)) == -1)
			;
		i++;
	}
}

void bash_execs(char *input, char **args, t_env *env, int *fd)
{
	char *path;
	__pid_t pid;
	int x = 0;

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
	waitpid(pid, NULL, 0);
}