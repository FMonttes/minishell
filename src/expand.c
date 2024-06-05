/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:48:47 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 10:59:04 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*search_and_replace_customized(char *s, char old, char new)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i] == old && s[i + 1] == old)
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

// static char	*join_second_p(char *joined, char *second_p)
// {
// 	if (second_p[0] == '$' && !second_p[1])
// 	{
// 		return (joined);
// 	}
// 	else if (second_p[0] == '$' && ft_isspace(second_p[1]))
// 	{
// 		joined = ft_strjoin(joined, second_p + 1);
// 		return (joined);
// 	}
// 	joined = ft_strjoin(joined, second_p);
// 	free(second_p);
// 	return (joined);
// }

char	*expand_word(char *word, t_env *env)
{
	char	*first_p;
	char	*joined;
	char	*teste;

	if (!ft_strchr(word, '$'))
		return (ft_strdup(word));
	{
		first_p = ft_strdup("");
		ft_strlcpy(first_p, word, count_til_c(word, '$') + 1);
		teste = get_env_var_value(env, get_env_var_name(word));
		joined = ft_strjoin(first_p, teste);
		free(first_p);
	}
	return (joined);
}
