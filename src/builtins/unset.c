/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:35:30 by fmontes           #+#    #+#             */
/*   Updated: 2024/06/05 13:23:45 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset_command(t_word *data, t_env *env)
{
	if (!data->next && ft_strncmp("unset", data->word,
			ft_strlen(data->word)) == 0)
	{
		ft_printf("%s: not enough arguments\n", data->word);
	}
	else if (ft_strncmp("unset", data->word, ft_strlen(data->word)) == 0)
	{
		list_remove_if(&env, data->next->word, ft_strncmp);
	}
}
