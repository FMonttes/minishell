/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_execs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:58:27 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/07 10:11:36 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int bash_execs(char *input, char **env)
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
		if ((execve(cmd, args, env)) == -1)
		{
			printf("Error\n");
			return (1);
		}
	}
	waitpid(pid, NULL, 0);
	return 0;
}