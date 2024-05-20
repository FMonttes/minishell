/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:19:04 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/20 15:05:35 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int heredoc(char *cmd, t_env *env, int *fd)
{
	int flag = 0;
	char *joined = ft_strdup("");

	int input_fd;
	int output_fd;
	char **args;
	int i;
	char *delimitador;
	char *input;

	i = 0;
	args = ft_split(cmd, ' ');
	/*while (cmd[i])
	{
		if (hidenp("<<", cmd) == 1)
	}*/
	while (args[i])
	{
		if (ft_strncmp(args[i], "<<", ft_strlen(args[i])) == 0)
		{
			args[i] = NULL;
			delimitador = args[i + 1];
			while (1)
			{
				input = readline(">");
				input = ft_strtrim(join_expand(input, env), " 	");
				if (ft_strncmp(input, delimitador, ft_strlen(delimitador)) == 0)
				{
					free(input);
					break;
				}
				joined = ft_strjoin(joined, input);
				joined = ft_strjoin(joined, "\n");
				free(input);
			}
			flag = 1;
		}
		i++;
	}
	if (flag)
	{
		int fd[2];
		__pid_t pid;

		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);

			exec(cmd, args, env);
		}
		close(fd[0]);
		write(fd[1], joined, ft_strlen(joined));
		close(fd[1]);
		waitpid(pid, NULL, 0);
		return (1);
	}
	return (0);
}