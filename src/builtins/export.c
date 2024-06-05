/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:26:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/06/05 13:23:27 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export_command(t_word *data, t_env *env)
{
	if (!data->next && ft_strncmp("export", data->word,
			ft_strlen(data->word)) == 0)
		return ;
	else if (ft_strncmp("export", data->word, ft_strlen(data->word)) == 0)
	{
		append_env_var(env, data->next->word);
	}
}
