/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:26:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/23 12:22:35 by fmontes          ###   ########.fr       */
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