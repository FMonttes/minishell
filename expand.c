#include "minishell.h"

char	*search_and_replace_customized(char *s, char old, char new)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == old && s[i + 1] == old)
		{
			i++;
			continue ;
		}
		else if (s[i] == old)
			s[i] = new;
		i++;
	}
	return (s);
}

static char	*join_second_p(char *joined, char *second_p)
{
	if (second_p[0] == '$' && !second_p[1])
	{
		free(second_p);
		return (joined);
	}
	else if (second_p[0] == '$' && ft_isspace(second_p[1]))
	{
		joined = ft_strjoin(joined, second_p + 1);
		free(second_p);
		return (joined);
	}
	joined = ft_strjoin(joined, second_p);
	free(second_p);
	return (joined);
}

char	*expand_word(char *word, t_env *env)
{
	char	*first_p;
	char	*second_p;
	char	*joined;

	{
		first_p = ft_strdup("");
		ft_strlcpy(first_p, word, count_til_c(word, '$') + 1);
		joined = ft_strjoin(first_p,
			get_env_var_value(env, get_env_var_name(word)));
		free(first_p);
	}
	{
		second_p = ft_strdup("");
		ft_strlcpy(second_p, ft_strchr(word, '$') + get_env_var_name_size(word) + 1,
			ft_strlen(ft_strchr(word, '$') + get_env_var_name_size(word)) + 1);
		joined = join_second_p(joined, second_p);
	}
	if (ft_strchr(joined, '$'))
		joined = expand_word(joined, env);
	return (joined);
}
