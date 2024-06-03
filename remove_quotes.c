#include "minishell.h"

static int	count_chars(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != SINGLE_QUOTE && line[i] != DOUBLE_QUOTES)
			count++;
		i++;
	}
	return (count);
}

char	*remove_quotes2(char *line)
{
	char	*all_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	all_line = malloc((sizeof(char) * count_chars(line) + 1));
	if (!all_line)
		return (NULL);
	while (line[i])
	{
		if (line[i] != SINGLE_QUOTE && line[i] != DOUBLE_QUOTES)
			all_line[j++] = line[i];
		i++;
	}
	all_line[j] = '\0';
	return (all_line);
}

void	remove_quotes_all_prompt(t_word *prompt)
{
	char	*temp;

	temp = NULL;
	while (prompt)
	{
		temp = prompt->word;
		prompt->word = remove_quotes2(prompt->word);
		free(temp);
		prompt = prompt->next;
	}
}
