/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:29:39 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 11:12:30 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	head_init(t_word *head);

static int	ismeta(char *c);
static int	get_word_len(char *line);
static int	find_next_quotes(char *line);

t_word	*create_word_lst(char *input)
{
	int		word_len;
	t_word	*new_word;
	t_word	*word_lst;

	if (!input)
		return (NULL);
	word_lst = NULL;
	while (*input)
	{
		word_len = get_word_len(input);
		new_word = ft_lstnew(ft_substr(input, 0, word_len));
		ft_lstadd_back(&word_lst, new_word);
		input += word_len;
		while (ft_isspace(*input))
			input++;
	}
	head_init(word_lst);
	word_lst->raw_cmd = input;
	return (word_lst);
}

static int	get_word_len(char *line)
{
	int	word_len;

	if (ismeta(line))
		return (ismeta(line));
	word_len = 0;
	while (*line && !ismeta(line) && !ft_isspace(*line))
	{
		if (*line == '\'' || *line == '\"')
		{
			word_len += find_next_quotes(line) + 1;
			line += find_next_quotes(line) + 1;
		}
		else
		{
			word_len++;
			line++;
		}
	}
	return (word_len);
}

static int	ismeta(char *c)
{
	if ((c[0] == '<' && c[1] == '<') || (c[0] == '>' && c[1] == '>'))
		return (2);
	else if (*c == '|' || *c == '>' || *c == '<')
		return (1);
	return (0);
}

static int	find_next_quotes(char *line)
{
	char	quote;
	int		next_quote_distance;

	if (!line || !*line)
		return (0);
	quote = *line;
	line++;
	next_quote_distance = 1;
	while (*line != quote)
	{
		if (!*line)
			return (-1);
		next_quote_distance++;
		line++;
	}
	return (next_quote_distance);
}

static void	head_init(t_word *head)
{
	t_word	*aux;

	if (!head)
		return ;
	aux = head;
	while (aux)
	{
		aux->head = head;
		aux = aux->next;
	}
	return ;
}
