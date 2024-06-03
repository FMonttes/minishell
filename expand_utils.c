#include "minishell.h"

size_t	count_til_c(char *word, char c)
{
	size_t	counter;

	counter = 0;
	while (word[counter] && word[counter] != c)
		counter++;
	return (counter);
}

size_t	get_env_var_name_size(char *string)
{
	size_t	i;
	size_t	j;
	size_t	counter;

	counter = -1;
	i = 0;
	while (string[i])
	{
		if (string[i] == '$')
		{
			counter = 0;
			j = i + 1;
			while (string[j] && !ft_isspace(string[j]))
			{
				if (string[j] == '$')
					return (counter);
				counter++;
				j++;
			}
			if (!string[j] || ft_isspace(string[j]))
				return (counter);
		}
		i++;
	}
	return (counter);
}

char	*get_env_var_value(t_env *env, char *var_name)
{
	size_t	size;
	t_env	*current;

	if (ft_strlen(var_name) == 0)
		return (ft_strdup("@"));
	else if (var_name[0] == '$')
		return (ft_itoa(getpid()));
	current = env;
	while (current)
	{
		if (ft_strncmp(var_name, current->env_var_s, 
			count_til_c(current->env_var_s, '=')) == 0)
			return (ft_strchr(current->env_var_s, '=') + 1);
		current = current->next;
	}
	return (ft_strdup(""));
}

char	*get_env_var_name(char *word)
{
	size_t	i;
	char	*str;
	char	*name;

	if (get_env_var_name_size(word) == -1)
		return (NULL);
	name = malloc(get_env_var_name_size(word));
	if (!name)
		return (NULL);
	str = ft_strchr(word, '$') + 1;
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		name[i] = str[i];
		i++;
		if (!str[i] || ft_isspace(str[i]))
			break ;
	}
	name[i] = '\0';
	return (name);
}
