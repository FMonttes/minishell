/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:25:32 by fmontes           #+#    #+#             */
/*   Updated: 2024/06/03 09:35:31 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int hidenp(char *cmd, char *input)
{
	int i = 0;
	int j = 0;

	while (input[j] && cmd[i])
	{
		if (input[j] == cmd[i])
			i++;
		j++;
	}
	if (cmd[i] == '\0')
		return 1;
	else
		return 0;
}
