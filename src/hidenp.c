/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:41:28 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 11:01:21 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	hidenp(char *cmd, char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[j] && cmd[i])
	{
		if (input[j] == cmd[i])
			i++;
		j++;
	}
	if (cmd[i] == '\0')
		return (1);
	else
		return (0);
}
