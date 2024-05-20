/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/20 14:51:52 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
struct termios save_term;

/*void sigint_handler(int sig)
{
	ft_printf("oi");
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}

void sigquit_handler(int sig)
{
	t_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putnbr_fd(sig, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	;
}

void init_signals(void)
{
	signal(SIGINT, sigint_handler);
	ignal(SIGQUIT, sigquit_handler);
}*/

int main(void)
{

	extern char **environ;
	char *input;
	int fd[2];
	t_env *env;

	env = init_env(environ);
	env->environ = environ;

	while (1)
	{
		input = readline("\x1b[1;36mminishell\u2192\x1b[0m ");
		input = ft_strtrim(join_expand(input, env), " 	");
		if (!input)
		{
			ft_printf("exit\n");
			break;
		}
		add_history(input);
		if (ft_strchr(input, '|'))
		{
			ft_pipe(input, env);
			continue;
		}
		if (check_builtin(input, env) == 1)
		{
			// char **args = ft_split(input, ' ');
			// heredoc(args);
			echo_command(input, env, fd);
			pwd(input, env, fd);
			redirect_env(input, env);
			continue;
		}
		if (hidenp("exit", input) == 1)
		{
			if (ft_exit(input) == 0) // vai dar leak
				break;
		}
		bash_execs(input, ft_split(input, ' '), env, fd);
		free(input);
	}
}