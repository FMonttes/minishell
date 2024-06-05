/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:13:50 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 11:00:58 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

char	*loop_env(t_env *env, char *var_name)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (ft_strncmp(var_name, current->env_var_s,
				count_til_c(current->env_var_s, '=')) == 0)
		{
			return (ft_strchr(current->env_var_s, '=') + 1);
		}
		current = current->next;
	}
	return (NULL);
}

char	*get_env_var_value(t_env *env, char *var_name)
{
	extern unsigned int	g_exit_status;
	char				*value;

	if (var_name == NULL || *var_name == '\0')
		return (ft_strdup("@"));
	if (var_name[0] == '$')
		return (get_env_var_value(env, "SYSTEMD_EXEC_PID"));
	if (var_name[0] == '?')
		return (ft_itoa(g_exit_status));
	value = loop_env(env, var_name);
	free(var_name);
	return (value);
}

char	*get_env_var_name(char *word)
{
	size_t	i;
	char	*str;
	char	*name;
	size_t	j;

	j = -1;
	if (get_env_var_name_size(word) == j)
		return (NULL);
	name = malloc(get_env_var_name_size(word));
	if (!name)
	{
		free(name);
		return (NULL);
	}
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
