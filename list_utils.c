#include "minishell.h"

t_word *creat_list(char *input)
{
	t_word *data = NULL;
	t_word *head = NULL;
	char **split;
	int i;

	split = ft_split(input, ' ');
	head = ft_lstnew(split[0]);
	data = head;

	i = 0;
	while (split[++i])
	{
		data->next = ft_lstnew(split[i]);
		data = data->next;
	}
	return head;
}

t_word *ft_lstnew(char *input)
{
	t_word *data = malloc(sizeof(t_word));

	if (!data)
		return NULL;
	data->word = input;
	data->flag = 0;
	data->next = NULL;
	return data;
}

void token(t_word *data)
{
	t_word *current = data;
	int i;

	while (current && current->word)
	{
		i = 0;
		while (current->word[i])
		{
			if (current->word[i] == '|')
				current->flag = PIPE;
			else if (current->word[i] == '<' && current->word[i + 1] == '<')
				current->flag = HDOC;
			else if (current->word[i] == '>' && current->word[i + 1] == '>')
				current->flag = APPEND;
			else if (current->word[i] == '<')
				current->flag = RDIN;
			else if (current->word[i] == '>')
				current->flag = RDOUT;
			else
				current->flag = WORD;
			i++;
		}
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
