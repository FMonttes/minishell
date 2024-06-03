#include "minishell.h"

void	apply_expand(t_word *prompt, t_env *env)
{
	char	*temp;

	temp = NULL;
	while (prompt)
	{
		if (ft_strchr(prompt->word, '$'))
		{
			temp = prompt->word;
			prompt->word = expand_word(prompt->word, env);
			prompt->word = search_and_replace_customized(prompt->word, '@', '$');
			free(temp);
		}
		prompt = prompt->next;
	}
}
