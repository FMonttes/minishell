/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/30 15:55:22 by jveras           ###   ########.fr       */
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

void echo_command(t_word *word)
{
	t_word	*current;

	if (ft_strncmp(word->word, "echo", ft_strlen(word->word)) == 0)
	{
		if (!word->next)
		{
			printf("\n");
			return ;
		}
		current = word;
		current = current->next;
		if (ft_strncmp(word->next->word, "-n", ft_strlen(word->next->word)) == 0)
			current = current->next;
		while (current)
		{
			printf("%s", current->word);
			if (current->next)
				printf(" ");
			current = current->next;
		}
		if (ft_strncmp(word->next->word, "-n", ft_strlen(word->next->word)) == 0)
			return ;
		printf("\n");
	}
}
