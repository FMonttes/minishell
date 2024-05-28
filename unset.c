/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:35:30 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/24 08:49:00 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void unset_command(char *input, t_env *env)
{
	char **args;

	args = ft_split(input, ' ');
	if (!args[1] && ft_strncmp("unset", args[0], ft_strlen(args[0])) == 0)
	{
		ft_printf("%s: not enough arguments\n", args[0]);
	}
	else if (ft_strncmp("unset", args[0], ft_strlen(args[0])) == 0)
	{
		list_remove_if(&env, args[1], ft_strncmp);
	}
}
