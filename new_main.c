#include "minishell.h"

void wait_cmds(t_word *node)
{
	t_word *aux;
	extern unsigned int g_exit_status;

	if (!node)
		return;
	aux = node;
	while (node)
	{
		if (node->pid != 0)
			waitpid(node->pid, &(node->status), 0);
		node = node->next;
	}
	return;
}

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
	old_in = dup(0);
	while (1)
	{
		dup2(old_in, 0);

		input = readline("\x1b[1;36mminishell\u2192\x1b[0m ");
		char *raw_input = ft_strdup(input);
		input = strq(input);
		input = ft_strtrim(join_expand(input, env), " \t");

		add_history(input);
		data = creat_list(input);
		data->raw_cmd = ft_strdup(raw_input);
		if (hidenp("pwd", data->word))
			pwd(data, env);

		token(data);
		executor(data, env);
		wait_cmds(data);
		close(0);
		// print_list(data);
		// Clean up (free memory)
	}
	return 0;
}
