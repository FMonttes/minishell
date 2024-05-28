/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:08:20 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/28 09:45:40 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd(t_word *data, t_env *env)
{
	char *current_directory;
	t_word *current;

	current = data;
	while (current)
	{
		if ((ft_strncmp(current->word, "pwd", ft_strlen(current->word)) == 0) &&
			count_quotes(data->raw_cmd) % 2 == 0)
		{
			current_directory = getcwd(NULL, 0);
			if (current_directory)
			{
				printf("builtin\n");
				ft_printf("%s\n", current_directory);
				free(current_directory);
			}
			else
				perror("Erro ao obter o diretório de trabalho atual");
		}
		else
			printf("error\n");
		current = current->next;
	}
}
