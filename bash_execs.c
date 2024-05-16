/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_execs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:58:27 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/16 16:53:50 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int bash_execs(char *input, t_env *env)
{
	int pid = fork();
	char *cmd = ft_strdup("/bin/");
	cmd = ft_strjoin(cmd, first_word(input));
	char **args;
	args = ft_split(input, ' ');
	if (pid < 0)
		perror("erorr");
	if (pid == 0)
	{
		redirect(args);
		heredoc(args);
		char **args2 = ft_split(getenv("PATH"), ':');
		int i = 0;
		while (args2[i])
		{
			cmd = ft_strjoin(args2[i], "/");
			if ((execve(ft_strjoin(cmd, first_word(input)),
						args, env->environ)) == -1)
				;
			i++;
		}
	}
	waitpid(pid, NULL, 0);
	return 0;
}