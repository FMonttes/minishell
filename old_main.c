/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/23 12:08:25 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../includes/minishell.h"

int	main(void)
{
	
	extern char **environ;
	char *input;
	// int fd[2];
	t_env *env;

	env = init_env(environ);
	env->environ = environ;

	while (1)
	{
		input = readline("\x1b[1;36mminishell\u2192\x1b[0m ");
		input = ft_strtrim(join_expand(input), " 	");
		if (!input)
		{
			ft_printf("exit\n");
			break ;
		}
		add_history(input);
		if (ft_strchr(input, '|'))
		{
			ft_pipe(input, env);
			continue ;
		}
		if (check_builtin(input, env) == 1)
		{
			// char **args = ft_split(input, ' ');
			// heredoc(args);
			echo_command(input, env);
			pwd(input, env);
			redirect_env(input, env);
			continue ;
		}
		if (hidenp("exit", input) == 1)
		{
			if (ft_exit(input) == 0) // vai dar leak
				break ;
		}
		bash_execs(input, ft_split(input, ' '), env);
		free(input);
	}
} */