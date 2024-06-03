#include "minishell.h"

unsigned int g_exit_status;

int main(void)
{
	extern char **environ;
	char *input;
	int fd[2];
	t_env *env;
	t_word *data;
	int old_in;

	env = init_env(environ);
	env->environ = environ;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		printf("%d", g_exit_status);
		input = readline("\x1b[1;36mminishell\u2192\x1b[0m ");

		if (!input || input[0] == '\0')
			continue;
		add_history(input);

		data = create_word_lst(input);
		remove_quotes_all_prompt(data);
		apply_expand(data, env);

		token(data);
		executor(data, env);
		wait_cmds(data);
		/* print_list(data); */
	}
	return 0;
}
