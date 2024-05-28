/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:26:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/24 08:35:26 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void export_command(char *input, t_env *env)
{
	char **args;
	args = ft_split(input, ' ');

	if (!args[1] && ft_strncmp("export", args[0], ft_strlen(args[0])) == 0)
		return;
	else if (ft_strncmp("export", args[0], ft_strlen(args[0])) == 0)
	{
		append_env_var(env, remove_extra_spaces(input, 1) + 7);
	}
}
