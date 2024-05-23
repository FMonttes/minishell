/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_execs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:14:45 by felperei          #+#    #+#             */
/*   Updated: 2024/05/23 12:14:38 by fmontes          ###   ########.fr       */
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

char **fill_list(t_word *data)
{
	char **ret;
	t_word *current;
	int i;
	int z;

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
		printf("%s", ret[z]);
		z++;
		current = current->next;
	}
	ret[z] = NULL;

	return (ret);
}

void exec(t_word *data, t_env *env)
{
	t_word *current;
	int i;
	char *path;
	int ok;
	char *full_path;
	char **args2;
	char *cmd;
	// extern unsigned int exit_status;
	current = data;
	current->cmds = fill_list(data);
	i = 0;
	// while (current)
	// {
	if (current->word[0] == '.' || current->word[0] == '/')
		execve(current->word, current->cmds, env_list_to_sstrs(env));
	//     current = current->next;
	// }

	args2 = ft_split(getenv("PATH"), ':');
	i = 0;
	while (args2[i])
	{
		cmd = ft_strjoin(args2[i], "/");
		full_path = ft_strjoin(cmd, current->word);

		if (access(full_path, F_OK) == 0)
		{
			ok = access(full_path, F_OK);
			break;
		}
		i++;
	}
	if (execve(full_path, current->cmds, env->environ) == -1)
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
	t_word *word;
	char **cmds;
	// extern unsigned int exit_status;
	word = data;
	cmds = fill_list(word);
	printf("%s", cmds[0]);
	if (!word)
		return;
	pid = fork();
	if (pid == 0)
		exec(data, env);
	waitpid(pid, NULL, 0);
	// exit_status = WEXITSTATUS(status);
}