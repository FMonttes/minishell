/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/28 08:31:44 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count_quotes(char *input)
{
	int i;
	int quotes;

	i = 0;
	quotes = 0;
	while (input[i])
	{
		if (input[i] == 39 || input[i] == 34)
			quotes++;
		i++;
	}
	return quotes;
}

static void maintain_double_quotes_spaces(char **str, int *i, int *j)
{
	if ((*str)[*i] && (*str)[*i] == DOUBLE_QUOTES)
	{
		(*i)++;
		while ((*str)[*i] && (*str)[*i] != DOUBLE_QUOTES)
		{
			(*str)[*j] = (*str)[*i];
			(*j)++;
			(*i)++;
		}
		(*i)++;
		(*str)[(*j)++] = ' ';
	}
}

char *remove_extra_spaces(char *str, int maintain_double_q_spaces)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (maintain_double_q_spaces)
			maintain_double_quotes_spaces(&str, &i, &j);
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		{
			if (str[i] == DOUBLE_QUOTES && maintain_double_q_spaces)
				maintain_double_quotes_spaces(&str, &i, &j);
			str[j] = str[i];
			if (str[i + 1] == ' ' || str[i + 1] == '\t')
				str[++j] = ' ';
			j++;
			i++;
		}
	}
	if (str[j - 1] == ' ' || str[j - 1] == '\t')
		j--;
	str[j] = '\0';
	return (str);
}

void echo_command(char *input, t_env *env)
{
	char **args;
	args = ft_split(input, ' ');
	int pid = fork();
	if (pid == 0)
	{
		if (!args[1] && ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0)
			ft_printf("\n");
		else if (ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0 && ft_strncmp("-n", args[1], ft_strlen(args[1])) == 0)
			ft_printf("%s", remove_extra_spaces(input, 1) + 8);
		else if (ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0)
			ft_printf("%s\n", remove_extra_spaces(input, 1) + 5);
		exit(0);
	}
	wait(NULL);
}
