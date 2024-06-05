/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:34:12 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 11:47:07 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	implemente_prompt(char *input, t_word *data, t_env *env)
{
	while (1)
	{
		input = readline("\x1b[1;36mminishell\u2192\x1b[0m ");
		if (!input)
		{
			ft_printf("exit\n");
			exit(1);
		}
		if (input[0] == '\0')
			continue ;
		add_history(input);
		data = create_word_lst(input);
		remove_quotes_all_prompt(data);
		apply_expand(data, env);
		token(data);
		executor(data, env);
		wait_cmds(data);
		free_list(data);
		free(input);
	}
}

int	count_quotes(char *input)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (input[i])
	{
		if (input[i] == 39 || input[i] == 34)
			quotes++;
		i++;
	}
	return (quotes);
}
