#include "minishell.h"

void token(t_word *data)
{
	t_word *current = data;
	int i;

	while (current && current->word)
	{
		i = 0;

		if (current->word[i] == '|')
			current->flag = PIPE;
		else if (!ft_strncmp("<<", current->word, 3))
			current->flag = HDOC;
		else if (!ft_strncmp(">>", current->word, 3))
			current->flag = APPEND;
		else if (current->word[i] == '<')
			current->flag = RDIN;
		else if (current->word[i] == '>')
			current->flag = RDOUT;
		else
			current->flag = WORD;
		current = current->next;
	}
}

void print_list(t_word *head)
{
	t_word *current = head;
	t_tkn token_type;

	printf("\n");
	while (current)
	{
		printf("%d :: \e[0;31m%s\e[0m\n", current->flag, current->word);
		current = current->next;
	}
}

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
