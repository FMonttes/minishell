/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:10:02 by fmontes           #+#    #+#             */
/*   Updated: 2024/06/05 11:06:12 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exit(t_word *data)
{
	t_word	*current;

	current = data;
	if (ft_strncmp(current->word, "exit", ft_strlen("exit")) == 0
		&& count_quotes(current->word) % 2 == 0)
	{
		ft_printf("exit\n");
		return (0);
	}
	else
		ft_printf("exit: command not found\n");
	return (1);
}
