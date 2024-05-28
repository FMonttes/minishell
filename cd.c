/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:07:19 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/28 09:22:21 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void cd(t_word *data)
{
	char *cmd;

	t_word *current;
	current = data;
	if (ft_strncmp("cd", current->word, ft_strlen(current->word)) == 0 && current->next == NULL)
	{
		chdir(getenv("HOME"));
		return;
	}
	if (count_quotes(current->raw_cmd) % 2 == 0)
	{
		if (chdir(current->next->word) == 0)
		{
			ft_printf("buuitl\n");
			return;
		}
		else
			ft_printf("Diretório inexistente\n");
	}
}
