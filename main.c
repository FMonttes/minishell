/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/07 14:45:08 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	extern char **environ;
	char *input;
	int fd[2];

	t_env *env = init_env(environ);
	while (1)
	{
		input = readline("\x1b[1;36mminishell\u2192\x1b[0m ");
		add_history(input);
		/*if (ft_strchr(input, '|'))
		{
			ft_pipe(input, env, fd);
			continue;
		}*/
		if (check_builtin(input, env) == 1)
		{
			echo_command(input);
			pwd(input);
			redirect_env(input, env);
			continue;
		}
		// bash_execs(input, env);
		if (hidenp("exit", input) == 1)
		{
			if (ft_exit(input) == 0) // vai dar leak
				break;
		}
		free(input);
	}
}
