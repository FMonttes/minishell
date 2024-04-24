/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/24 14:43:38 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char *input;
	int fd[2];
	while (1)
	{
		input = readline("\x1b[1;36mminishell\u2192\x1b[0m ");
		add_history(input);
		if (check_builtin(input, env))
			continue;
		int pid = fork();
		if (pid == 0)
		{
			if (ft_strchr(input, '|'))
			{
				pipe_exec(input, fd);
				continue;
			}
			bash_execs(input, env);
		}
		if (hidenp("exit", input) == 1)
		{
			if (ft_exit(input) == 0) // vai dar leak
				break ;
		}
		waitpid(pid, NULL, 0);
		free(input);
	}
}